# Competitive Programming (CP)

Repository for competitive programming problem solutions, contest templates, and automated workflows.

## Environment & Tooling
- **Language Standard:** GNU C++23 (`-std=c++23 -O2 -pipe`)
- **Compiler:** GNU GCC 16 / Apple Clang with Precompiled Headers (`~/.cp_pch/stdc++.pch`)
- **Platform:** macOS (Apple Silicon)

## Workflow Commands
Consolidated under the unified `cp` command:
- `cp paste <problem>`: Parses the problem statement from clipboard, strips web noise, and embeds statement in clean ASCII comments with template.
- `cp <problem>`: Lightning-fast compilation (~0.13s) using precompiled headers, with outputs placed in `/tmp` to keep folders clean.
- `cp`: Default runner for `main.cpp`.

## New-file staging
To automatically stage non-ignored files created after the watcher starts, run:

```bash
python3 scripts/watch_and_stage.py
```

The watcher does not commit or push changes. Stop it with `Ctrl-C`.
