#!/usr/bin/env python3
import sys
import os
import re
import subprocess
import json
import time
import urllib.request
import unicodedata

TEMPLATE_PATH = "/Users/kishorkumarparoi/Desktop/CP/template.cpp"
CF_HANDLE = "0x.alive"

def get_clipboard():
    try:
        res = subprocess.run(["pbpaste"], capture_output=True, text=True, check=True)
        return res.stdout
    except Exception as e:
        print(f"Error reading clipboard: {e}")
        return ""

def set_clipboard(text):
    try:
        p = subprocess.Popen(["pbcopy"], stdin=subprocess.PIPE)
        p.communicate(text.encode("utf-8"))
    except Exception as e:
        print(f"Error writing to clipboard: {e}")

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
    text = unicodedata.normalize('NFKD', text)
    return text.encode('ascii', 'ignore').decode('ascii')

def clean_problem_statement(raw):
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

def get_problem_info(file_path):
    """Detects contestId and problemIndex from directory, problem.json, filename, or code."""
    parent = os.path.dirname(file_path) if file_path else ""
    parent = parent or "."

    # 1. Check problem.json
    prob_json = os.path.join(parent, "problem.json")
    if os.path.exists(prob_json):
        try:
            with open(prob_json, "r") as f:
                d = json.load(f)
                pid = str(d.get("id", ""))
                m = re.match(r"^(\d+)([A-Za-z]\d?)$", pid)
                if m:
                    return m.group(1), m.group(2).upper(), d.get("name", "")
        except Exception:
            pass

    # 2. Check parent folder name (e.g. 2278A. Fraction and Six)
    parent_name = os.path.basename(os.path.abspath(parent))
    m = re.search(r"(\d+)[-_]?([A-Za-z]\d?)", parent_name)
    if m:
        prob_name = parent_name.split(".", 1)[-1].strip() if "." in parent_name else ""
        return m.group(1), m.group(2).upper(), prob_name

    # 3. Check filename
    if file_path:
        filename = os.path.basename(file_path)
        m = re.search(r"(\d+)[-_]?([A-Za-z]\d?)", filename)
        if m:
            return m.group(1), m.group(2).upper(), ""

    # 4. Check code comments
    if file_path and os.path.exists(file_path):
        try:
            with open(file_path, "r", errors="ignore") as f:
                code = f.read()
            m = re.search(r"codeforces\.com/(?:contest|problemset/problem)/(\d+)/([A-Za-z]\d?)", code)
            if m:
                return m.group(1), m.group(2).upper(), ""
        except Exception:
            pass

    return "", "", ""

def fetch_recent_submissions(handle=CF_HANDLE, count=10):
    try:
        url = f"https://codeforces.com/api/user.status?handle={handle}&from=1&count={count}"
        req = urllib.request.Request(url, headers={"User-Agent": "Mozilla/5.0"})
        with urllib.request.urlopen(req, timeout=4) as res:
            data = json.loads(res.read().decode())
            if data.get("status") == "OK":
                return data.get("result", [])
    except Exception as e:
        pass
    return []

def format_verdict_str(sub):
    verdict = sub.get("verdict")
    tests = sub.get("passedTestCount", 0)

    VERDICTS = {
        "OK": "\033[1;92mACCEPTED (AC) 🎉\033[0m",
        "WRONG_ANSWER": "\033[1;91mWRONG ANSWER (WA) ❌\033[0m",
        "TIME_LIMIT_EXCEEDED": "\033[1;93mTIME LIMIT EXCEEDED (TLE) ⏱️\033[0m",
        "MEMORY_LIMIT_EXCEEDED": "\033[1;93mMEMORY LIMIT EXCEEDED (MLE) 💾\033[0m",
        "COMPILATION_ERROR": "\033[1;91mCOMPILATION ERROR (CE) ⚠️\033[0m",
        "RUNTIME_ERROR": "\033[1;91mRUNTIME ERROR (RE) 💥\033[0m",
        "CHALLENGED": "\033[1;91mHACKED / CHALLENGED ⚔️\033[0m",
        "SKIPPED": "\033[1;90mSKIPPED ⏭️\033[0m",
        "PARTIAL": "\033[1;94mPARTIAL POINTS\033[0m",
        "IDLENESS_LIMIT_EXCEEDED": "\033[1;93mIDLENESS LIMIT EXCEEDED ⏳\033[0m",
    }

    if not verdict or verdict == "TESTING":
        return f"\033[1;96mTESTING (on test {tests + 1})\033[0m"

    v_base = VERDICTS.get(verdict, f"\033[1;97m{verdict}\033[0m")
    if verdict == "OK":
        return f"{v_base} (Passed all {tests} tests)"
    elif verdict in ("WRONG_ANSWER", "TIME_LIMIT_EXCEEDED", "MEMORY_LIMIT_EXCEEDED", "RUNTIME_ERROR", "IDLENESS_LIMIT_EXCEEDED"):
        return f"{v_base} on test {tests + 1}"
    return v_base

def format_time_ago(seconds_ago):
    if seconds_ago < 60:
        return f"{int(seconds_ago)}s ago"
    elif seconds_ago < 3600:
        return f"{int(seconds_ago // 60)}m ago"
    else:
        return f"{int(seconds_ago // 3600)}h ago"

def print_submission_summary(sub):
    prob = sub.get("problem", {})
    p_id = f"{prob.get('contestId', '')}{prob.get('index', '')}"
    p_name = prob.get("name", "")
    full_prob = f"{p_id} - {p_name}" if p_name else p_id
    sub_id = sub.get("id")
    v_str = format_verdict_str(sub)
    time_ms = sub.get("timeConsumedMillis", 0)
    mem_kb = sub.get("memoryConsumedBytes", 0) // 1024
    lang = sub.get("programmingLanguage", "C++")
    age_sec = time.time() - sub.get("creationTimeSeconds", time.time())
    time_str = format_time_ago(max(0, age_sec))

    print("\n" + "=" * 60)
    print(f" Problem   : \033[1m{full_prob}\033[0m")
    print(f" Verdict   : {v_str}")
    print(f" Stats     : {time_ms} ms | {mem_kb} KB | {lang}")
    print(f" Info      : Submission #{sub_id} ({time_str})")
    print("=" * 60 + "\n")

def track_submission(sub_id, handle=CF_HANDLE, timeout=60):
    spinner = ["⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"]
    spin_idx = 0
    start_time = time.time()

    while time.time() - start_time < timeout:
        subs = fetch_recent_submissions(handle, count=5)
        for s in subs:
            if s.get("id") == sub_id:
                verdict = s.get("verdict")
                tests = s.get("passedTestCount", 0)

                if not verdict or verdict == "TESTING":
                    s_char = spinner[spin_idx % len(spinner)]
                    spin_idx += 1
                    print(f"\r{s_char} Submission #{sub_id}: Running on test {tests + 1}...   ", end="", flush=True)
                else:
                    print("\r\033[K", end="")
                    print_submission_summary(s)
                    return
        time.sleep(1)

    print("\r\033[K[CP Status] Still judging. Run 'cp submit' or 'cp status' again in a moment.\n")

def cmd_submit(file_path=""):
    # 1. Resolve file path if not given
    if not file_path:
        for candidate in ["Main.cpp", "main.cpp"]:
            if os.path.exists(candidate):
                file_path = candidate
                break
        if not file_path:
            cpps = [f for f in os.listdir(".") if f.endswith(".cpp")]
            if cpps:
                file_path = cpps[0]

    # 2. If a C++ file exists, sanitize & copy clean code to clipboard
    if file_path and os.path.exists(file_path):
        try:
            with open(file_path, "r", encoding="utf-8", errors="ignore") as f:
                raw_code = f.read()
            # Strip problem statement comment banner
            clean_code = re.sub(r'/\*\s*={10,}[\s\S]*?={10,}\s*\*/\s*', '', raw_code)
            clean_code = sanitize_ascii(clean_code).strip()
            set_clipboard(clean_code)
            print(f"📋 Clean ASCII code from '{file_path}' copied to clipboard!")
        except Exception as e:
            pass

    # 3. Detect problem
    contest_id, prob_idx, prob_name = get_problem_info(file_path)
    target_prob = f"{contest_id}{prob_idx}" if contest_id and prob_idx else ""

    if target_prob:
        display_name = f"{target_prob} ({prob_name})" if prob_name else target_prob
        print(f"🎯 Target Problem: {display_name} | Handle: {CF_HANDLE}")
    else:
        print(f"🎯 Handle: {CF_HANDLE}")

    # 4. Fetch recent submissions
    subs = fetch_recent_submissions(CF_HANDLE, count=10)
    if not subs:
        print("Could not retrieve submissions from Codeforces. Check your network connection.")
        return

    # Find the latest submission matching the target problem, or fallback to the latest submission
    matching_sub = None
    if contest_id and prob_idx:
        for s in subs:
            p = s.get("problem", {})
            if str(p.get("contestId")) == str(contest_id) and str(p.get("index")).upper() == str(prob_idx).upper():
                matching_sub = s
                break

    latest_sub = matching_sub or subs[0]
    sub_id = latest_sub.get("id")
    verdict = latest_sub.get("verdict")
    age = time.time() - latest_sub.get("creationTimeSeconds", 0)

    # If the submission is currently being tested
    if not verdict or verdict == "TESTING":
        print(f"Submission #{sub_id} is currently judging...")
        track_submission(sub_id)
        return

    # If the submission was made very recently (< 45s ago), it's the one user just submitted
    if age < 45:
        print_submission_summary(latest_sub)
        return

    # Otherwise, show last known verdict
    print_submission_summary(latest_sub)

    # And wait briefly for a new submission in case user is submitting right now
    last_id = subs[0].get("id")
    print("👀 Watching for new submission... (Submit on Codeforces now, or press Ctrl+C to exit)")

    spinner = ["⠋", "⠙", "⠹", "⠸", "⠼", "⠴", "⠦", "⠧", "⠇", "⠏"]
    spin_idx = 0
    start_time = time.time()

    try:
        while time.time() - start_time < 30:
            s_char = spinner[spin_idx % len(spinner)]
            spin_idx += 1
            elapsed = int(time.time() - start_time)
            print(f"\r{s_char} Waiting for submission ({30 - elapsed}s remaining)...   ", end="", flush=True)

            cur_subs = fetch_recent_submissions(CF_HANDLE, count=3)
            if cur_subs and cur_subs[0].get("id") != last_id:
                new_sub = cur_subs[0]
                new_id = new_sub.get("id")
                print(f"\r\033[K✨ New submission detected: #{new_id}!")
                track_submission(new_id)
                return

            time.sleep(1.2)
        print("\r\033[KDone. Run 'cp submit' anytime to check status.")
    except KeyboardInterrupt:
        print("\r\033[K")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        cmd_submit()
        sys.exit(0)

    cmd = sys.argv[1]
    target = sys.argv[2] if len(sys.argv) > 2 else ""

    if cmd == "paste":
        cmd_paste(target or "main.cpp")
    elif cmd in ("submit", "status"):
        cmd_submit(target)
    else:
        # If run directly with a filename e.g. cf_tool.py main.cpp
        if cmd.endswith(".cpp"):
            cmd_submit(cmd)
        else:
            print("Usage: cf_tool.py [paste|submit|status] [file.cpp]")
