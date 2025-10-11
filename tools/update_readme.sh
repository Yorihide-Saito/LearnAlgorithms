#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$ROOT_DIR"

# ---------- 1) 集計: src/abc*/**/*.cpp だけ ----------
# 各コンテスト(abc300, abc301,...) と、その配下の cpp 数を表にする
mapfile -t ABC_DIRS < <(find src -maxdepth 1 -type d -name "abc*" | sort)

TOTAL=0
TABLE_HEADER='| Contest | Files |\n|:--|--:|'
TABLE_ROWS=""

for d in "${ABC_DIRS[@]}"; do
  name="$(basename "$d")"
  cnt=$(find "$d" -type f -name "*.cpp" | wc -l | tr -d ' ')
  if [[ "$cnt" -gt 0 ]]; then
    TABLE_ROWS+=$'\n'"| ${name} | ${cnt} |"
    TOTAL=$((TOTAL + cnt))
  fi
done

# 直近10件ぐらいの「最新コミット済みファイル例」（任意）
# show up to 10 newest ABC cpp paths for motivation
mapfile -t LATEST < <(git ls-files 'src/abc*/**/*.cpp' | xargs -I{} -- stat -c '%Y\t%n' {} 2>/dev/null | sort -nr | head -n 10 | cut -f2-)

LATEST_MD=""
if ((${#LATEST[@]} > 0)); then
  LATEST_MD=$'\n**最近の追加(最大10件):**\n\n'
  for f in "${LATEST[@]}"; do
    LATEST_MD+="- ${f}"$'\n'
  done
fi

DATE_JST="$(date +'%Y-%m-%d %H:%M:%S %Z')"

# ---------- 2) 置換するブロックを構築 ----------
# README 内の下記マーカーをまるごと差し替え:
# <!-- ABC_COUNT_START -->
# ...（自動生成）
# <!-- ABC_COUNT_END -->
read -r -d '' NEW_BLOCK <<EOF
<!-- ABC_COUNT_START -->
### 🧮 ABC の C++ 実装数

- 合計: **${TOTAL}** ファイル  
- 最終更新: ${DATE_JST}

${LATEST_MD}
${TABLE_HEADER}
${TABLE_ROWS}

> 対象は \`src/abc*/**/*.cpp\` のみ。Actions が push 時に自動更新します。
<!-- ABC_COUNT_END -->
EOF

# ---------- 3) README.md を安全に置換 ----------
if [[ ! -f README.md ]]; then
  echo "# AtCoder" > README.md
  echo "" >> README.md
  echo "<!-- ABC_COUNT_START -->" >> README.md
  echo "<!-- ABC_COUNT_END -->" >> README.md
fi

# Perl でマーカー区間を一括置換（改行を含むブロックOK）
perl -0777 -pe 's/<!-- ABC_COUNT_START -->.*?<!-- ABC_COUNT_END -->/$ENV{NEW_BLOCK}/s' \
  README.md > README.tmp && mv README.tmp README.md

echo "Updated README with ABC cpp count: ${TOTAL}"