#!/usr/bin/env python3
"""Stage non-ignored regular files created after this watcher starts."""

from __future__ import annotations

import argparse
import os
import subprocess
import time
from pathlib import Path


def files_in(root: Path) -> set[Path]:
    files: set[Path] = set()
    for directory, directory_names, file_names in os.walk(root):
        directory_names[:] = [
            name for name in directory_names if name != ".git"
        ]
        for name in file_names:
            path = Path(directory) / name
            if path.is_file():
                files.add(path.relative_to(root))
    return files


def is_ignored(root: Path, path: Path) -> bool:
    result = subprocess.run(
        ["git", "check-ignore", "--quiet", "--", str(path)],
        cwd=root,
        check=False,
    )
    return result.returncode == 0


def stage_new_files(root: Path, known_files: set[Path]) -> set[Path]:
    current_files = files_in(root)
    for path in sorted(current_files - known_files):
        if not is_ignored(root, path):
            subprocess.run(["git", "add", "--", str(path)], cwd=root, check=True)
            print(f"Staged new file: {path}", flush=True)
    return current_files


def main() -> int:
    parser = argparse.ArgumentParser(
        description="Stage non-ignored files created while this command runs."
    )
    parser.add_argument(
        "--interval",
        type=float,
        default=1.0,
        help="Seconds between filesystem scans (default: 1.0)",
    )
    args = parser.parse_args()
    if args.interval <= 0:
        parser.error("--interval must be greater than zero")

    root = Path(
        subprocess.check_output(
            ["git", "rev-parse", "--show-toplevel"], text=True
        ).strip()
    )
    known_files = files_in(root)
    print(
        f"Watching {root} for new files. Press Ctrl-C to stop.",
        flush=True,
    )
    try:
        while True:
            time.sleep(args.interval)
            known_files = stage_new_files(root, known_files)
    except KeyboardInterrupt:
        print("\nStopped.", flush=True)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
