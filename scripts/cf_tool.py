#!/usr/bin/env python3
import sys
import os
import re
import subprocess
import unicodedata

TEMPLATE_PATH = "/Users/kishorkumarparoi/Desktop/CP/template.cpp"

def get_clipboard():
    try:
        res = subprocess.run(["pbpaste"], capture_output=True, text=True, check=True)
        return res.stdout
    except Exception as e:
        print(f"Error reading clipboard: {e}")
        return ""

def sanitize_ascii(text):
    """Replaces Unicode math symbols and emojis with clean ASCII equivalents."""
    replacements = {
        '≤': '<=', '≥': '>=', '≠': '!=',
        '—': '-', '–': '-', '−': '-',
        '’': "'", '‘': "'",
        '“': '"', '”': '"',
        '…': '...', '×': '*', '÷': '/'
    }
    for k, v in replacements.items():
        text = text.replace(k, v)
    # NFKD decomposes mathematical italics (𝑝, 𝑞, 𝚜𝚒𝚡, 𝑛, 𝑡) into plain ASCII letters
    text = unicodedata.normalize('NFKD', text)
    # Strip any emojis or unsupported unicode characters
    return text.encode('ascii', 'ignore').decode('ascii')

def clean_problem_statement(raw):
    """
    Strips all Codeforces navigation bars, user profile, footer, cloning links, etc.
    Extracts ONLY Title, Limits, Statement, Input/Output specs, Examples, and Notes.
    Converts all Unicode math characters to clean ASCII.
    """
    raw = sanitize_ascii(raw)

    title = ""
    time_limit = ""
    memory_limit = ""
    body = ""
    sample_inputs = []
    sample_outputs = []

    m_start = re.search(
        r"(?:^|\n)([A-Z]\d?[\.\s\-]+[^\n\r]+)\s*\n\s*time limit per test[:\s]*([^\n\r]+)\s*\n\s*memory limit per test[:\s]*([^\n\r]+)",
        raw,
        re.IGNORECASE
    )

    if m_start:
        title = m_start.group(1).strip()
        time_limit = m_start.group(2).strip()
        memory_limit = m_start.group(3).strip()
        body = raw[m_start.end():]
    else:
        m_title = re.search(r"^([A-Z]\d?[\.\s\-]+[^\n\r]+)", raw, re.MULTILINE)
        if m_title:
            title = m_title.group(1).strip()
            body = raw[m_title.end():]
        else:
            title = "Codeforces Problem"
            body = raw

    footer_patterns = [
        r"(?:Codeforces \(c\)|The only programming contests|Server time:|Desktop version|Privacy Policy|Supported by Telegram|Announcement|→ Submit\?|Custom Invocation)",
    ]
    for fp in footer_patterns:
        m_foot = re.search(fp, body, re.IGNORECASE)
        if m_foot:
            body = body[:m_foot.start()]

    body = re.sub(r"InputCopy", "Input:\n", body, flags=re.IGNORECASE)
    body = re.sub(r"OutputCopy", "Output:\n", body, flags=re.IGNORECASE)
    body = re.sub(r"Example[s]?\s*\n", "Example:\n", body, flags=re.IGNORECASE)

    ex_pattern = re.compile(
        r"Example:?\s*\n\s*Input:?\s*\n([\s\S]*?)\n\s*Output:?\s*\n([\s\S]*?)(?=(?:\n\s*Note|\n\s*Input:?|$))",
        re.IGNORECASE
    )
    for m in ex_pattern.finditer(body):
        s_in = m.group(1).strip()
        s_out = m.group(2).strip()
        if s_in:
            sample_inputs.append(s_in)
        if s_out:
            sample_outputs.append(s_out)

    body = re.sub(r"\n{3,}", "\n\n", body).strip()

    return {
        "title": title or "Codeforces Problem",
        "time_limit": time_limit or "Standard",
        "memory_limit": memory_limit or "Standard",
        "statement": body,
        "sample_input": sample_inputs[0] if sample_inputs else ""
    }

def cmd_paste(target_file):
    clip = get_clipboard().strip()
    if not clip:
        print("Clipboard is empty! Copy problem statement first (Cmd+A, Cmd+C on problem page).")
        return 1

    parsed = clean_problem_statement(clip)

    template = ""
    if os.path.exists(TEMPLATE_PATH):
        with open(TEMPLATE_PATH, "r") as f:
            template = f.read()

    banner = f"""/*
================================================================================
{parsed['title']}
Time Limit: {parsed['time_limit']} | Memory Limit: {parsed['memory_limit']}
================================================================================

{parsed['statement']}
================================================================================
*/

"""
    full_content = banner + template

    parent = os.path.dirname(target_file)
    if parent:
        os.makedirs(parent, exist_ok=True)

    with open(target_file, "w") as f:
        f.write(full_content)

    print(f"Created {target_file} (clean ASCII, 0 unusual characters)!")

    if parsed['sample_input']:
        in_file = os.path.join(parent or ".", "input.txt")
        with open(in_file, "w") as f:
            f.write(parsed['sample_input'] + "\n")
        print(f"Extracted sample test case to {in_file}")

    editor = "antigravity-ide" if subprocess.run(["which", "antigravity-ide"], capture_output=True).returncode == 0 else "code"
    subprocess.run([editor, "-r", target_file])

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: cf_tool.py paste <file.cpp>")
        sys.exit(1)

    cmd = sys.argv[1]
    target = sys.argv[2] if len(sys.argv) > 2 else "main.cpp"

    if cmd == "paste":
        cmd_paste(target)
