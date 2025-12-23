# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

This is an AtCoder competitive programming practice repository containing solutions and learning materials. The repository is organized into source code (`src/`), notes (`10_atcoder_notes/`, `20_algo_notes/`), and miscellaneous resources (`00_index/`).

## Repository Structure

```
AtCorder
├── 00_index          -> general workspace
├── 10_atcoder_notes  -> solution notes per ABC contest
├── 20_algo_notes     -> algorithm reference notes
└── src               -> source code solutions
    ├── abcXXX/       -> ABC contest folders (e.g., abc437/)
    ├── typical90/    -> Typical90 problem solutions
    ├── practice/     -> practice problems and algorithm study
    ├── knowledge/    -> algorithm reference implementations
    └── template.cpp  -> base template for new solutions
```

## Development Workflow

### Compile and Run Commands

The repository uses `g++-15` with C++17 standard:

```bash
# Compile
g++-15 -std=gnu++17 -O2 -Wall -Wextra -Wshadow -o main ./src/abc437/abc437.cpp

# Run with sample input
./main < sample.in
```

### Creating New ABC Contest Files

Use the `make_abc.sh` script to scaffold new contest directories:

```bash
# Create abc437 directory and files
./make_abc.sh 437

# Or with two arguments
./make_abc.sh 4 37
```

This creates `src/abcXXX/abcXXX.cpp` using the template.

## Coding Conventions for Competitive Programming

### Template Structure

All solutions should start with:
```cpp
#include<iostream>
using namespace std;
using ll = long long;

int main() {
    // solution code
    return 0;
}
```

### Competitive Programming Best Practices

When writing competitive programming solutions:

1. **Prefer simplicity over abstraction** - Direct, readable code is better than over-engineered solutions
2. **Avoid unnecessary data structures** - Use simple arrays, vectors, and maps rather than complex custom structures unless required by the problem
3. **Keep it concise** - Competitive programming values short, clear implementations
4. **Use standard library efficiently** - Prefer STL algorithms and containers
5. **Minimize helper functions** - Inline logic when it doesn't harm readability

### File Naming

Solutions follow these patterns:
- Main solution: `abcXXX.cpp` or `abcXXX_Y.cpp` (where Y is the problem letter)
- Alternative approaches: `abcXXX_Y_method.cpp` (e.g., `abc302_c_dfs.cpp`, `abc302_c_bitdp.cpp`)
- Answer files: `abcXXX_Y_ans.cpp` (reference implementations)

## Tool Recommendations

The repository recommends using `oj` (online-judge-tools) for testing solutions against AtCoder test cases.
