#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

# ---------- 1) 集計: src/abc*/**/*.cpp だけ ----------
# 各コンテスト(abc300, abc301,...) と、その配下の cpp 数を表にする
mapfile -t ABC_DIRS < <(find src -maxdepth 1 -type d -name "abc*" 2>/dev/null | sort || true)

TOTAL=0

for d in "${ABC_DIRS[@]:-}"; do
  name="$(basename "$d")"
  # -type f -name "*.cpp" を数える
  cnt="$(find "$d" -type f -name "*.cpp" 2>/dev/null | wc -l | tr -d ' ' || echo 0)"
  if [[ "${cnt:-0}" -gt 0 ]]; then
    TOTAL=$((TOTAL + cnt))
  fi
done

# JST（Actions の env: TZ=Asia/Tokyo を活用）
DATE_JST="$(date +'%Y-%m-%d %H:%M:%S %Z')"

# ---------- 2) 置換するブロックを構築 ----------
# README 内の下記マーカーをまるごと差し替え:
# <!-- ABC_COUNT_START -->
# ...（自動生成）
# <!-- ABC_COUNT_END -->
# ※ heredoc は「引用しない」EOFにして、シェル変数を展開させる（${TOTAL} 等）
NEW_BLOCK="$(cat <<EOF
<!-- ABC_COUNT_START -->
### 🧮 ABC の C++ 実装数

- 合計: **${TOTAL}** ファイル
- 最終更新: ${DATE_JST}

${TABLE_HEADER}

> 対象は \`src/abc*/**/*.cpp\` のみ。Actions が push 時に自動更新します。
<!-- ABC_COUNT_END -->
EOF
)"
export NEW_BLOCK

# ---------- 3) README.md を安全に置換 ----------
if [[ ! -f README.md ]]; then
  {
    echo "# AtCoder"
    echo
    echo "<!-- ABC_COUNT_START -->"
    echo "<!-- ABC_COUNT_END -->"
  } > README.md
fi

# Perl でマーカー区間を一括置換（改行を含むブロックOK）
perl -0777 -pe 's/<!-- ABC_COUNT_START -->.*?<!-- ABC_COUNT_END -->/$ENV{NEW_BLOCK}/s' \
  README.md > README.tmp && mv README.tmp README.md

echo "Updated README with ABC cpp count: ${TOTAL}"