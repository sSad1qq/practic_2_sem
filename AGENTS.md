# AGENTS.md

This file provides guidance to Codex (Codex.ai/code) when working with code in this repository.

## Project Overview

A collection of C++ programming assignments (task1–task5), each solving an independent problem. The primary IDE is **CLion** with CMake; each task also has a parallel **Visual Studio** solution (`.slnx` / `.vcxproj`) for MSVC builds.

## Build Commands

### CMake (CLion / command line)
```bash
# Configure (from repo root)
cmake -S . -B cmake-build-debug -DCMAKE_BUILD_TYPE=Debug

# Build
cmake --build cmake-build-debug

# Run the combined executable (tasks 1–3 are bundled; has multiple main() — needs per-task builds)
./cmake-build-debug/repos.exe
```

> **Note:** The root `CMakeLists.txt` lists `task1`, `task2`, and `task3` only and defines a single target `repos`. Tasks 4 and 5 have their own standalone VS solutions and are **not** in the root CMakeLists yet.

### Visual Studio (per-task)
Open `taskN/taskN.slnx` in Visual Studio 2022 and build/run from there. Each task compiles independently.

## Architecture

Each task follows the same three-file layout:
- `main.cpp` — entry point, handles console UTF-8 setup (`SetConsoleOutputCP(CP_UTF8)`) and user I/O
- `mod.h` — declarations + includes
- `mod.cpp` — implementations

### Task summaries

| Task | What it does |
|------|-------------|
| task1 | Computes two trigonometric expressions z1/z2 for a user-supplied angle (radians) |
| task2 | Evaluates a piecewise function F(x) over a range and prints a formatted table |
| task3 | Fills a `double[]` with random values in `[-10, 10]`; finds minimum, sums elements between the first two negatives, rearranges so `|x| < 1` elements come first |
| task4 | Reads a 10×10 matrix from `data.txt`, applies neighbor-averaging smoothing, prints sum of absolute values below the main diagonal |
| task5 | Stub — `main.cpp` and `mod.cpp` are empty; `mod.h` contains only `#pragma once` |

### Key implementation notes

- All programs are **Windows-only**: they include `<windows.h>` and call `SetConsoleOutputCP`/`SetConsoleCP` for UTF-8 Russian output.
- `task4/main.cpp` has the data file path **hardcoded** as `C:/Users/dyatl/source/repos/task4/data.txt`. Update this path if the repo is cloned elsewhere.
- `task4` uses raw `double**` heap-allocated matrices without deallocation — `createDoubleMatrix` / `read_matrix_from_file` allocate but nothing frees them.
- `task3::sum_of_el_btw_two_neg` will dereference a null pointer if fewer than two negative elements exist in the array.

## Adding a New Task

1. Create `taskN/main.cpp`, `taskN/mod.h`, `taskN/mod.cpp`.
2. Add `include_directories(taskN)` and the three source files to `add_executable` in `CMakeLists.txt` (or create a separate `add_executable` target to avoid `main()` conflicts).
