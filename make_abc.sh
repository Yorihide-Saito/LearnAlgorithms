#!/usr/bin/env bash
set -euo pipefail

# --- 引数処理 ---
if [ $# -eq 1 ]; then
  RAW_NUM="$1"
elif [ $# -eq 2 ]; then
  RAW_NUM="$1$2"
else
  echo "Usage:"
  echo "  $0 <abc number>        (例: $0 433)"
  echo "  $0 <part1> <part2>     (例: $0 4 33 -> 433)"
  exit 1
fi

# 数字チェック
for arg in "$@"; do
  if ! [[ "$arg" =~ ^[0-9]+$ ]]; then
    echo "Error: arguments must be digits only. got '$arg'"
    exit 1
  fi
done

NUM="$RAW_NUM"

# 3桁チェック
if ! [[ "$NUM" =~ ^[0-9]{3}$ ]]; then
  echo "Error: abc number must be exactly 3 digits. got '$NUM'"
  exit 1
fi

# --- テンプレート確認 & 自動生成 ---
TEMPLATE="src/template.cpp"

if [ ! -f "$TEMPLATE" ]; then
  echo "Template not found. Creating: $TEMPLATE"
  mkdir -p "$(dirname "$TEMPLATE")"
  cat > "$TEMPLATE" << 'EOF'
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // TODO: solve

    return 0;
}
EOF
fi

# --- abcXXX のフォルダ作成 ---
DIR="src/abc${NUM}"

if [ -d "$DIR" ]; then
  echo "Directory already exists, using it: $DIR"
else
  mkdir -p "$DIR"
  echo "Create directory: $DIR"
fi

# --- ファイル作成関数 ---
create_file() {
  local suffix="$1"
  local filename

  if [ -z "$suffix" ]; then
    filename="abc${NUM}.cpp"
  else
    filename="abc${NUM}_${suffix}.cpp"
  fi

  local path="${DIR}/${filename}"

  if [ -e "$path" ]; then
    echo "Skip:   $path (already exists)"
  else
    cp "$TEMPLATE" "$path"
    echo "Create: $path"
  fi
}

# --- メイン + A〜D の問題ファイルを生成 ---
create_file ""   # abc433.cpp

echo "Done for abc${NUM}"