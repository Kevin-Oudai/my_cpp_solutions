# Repository Agent Instructions

This repository is an archive of C++ textbook exercises. Treat it as a learning
archive first: solutions must match the chapter's covered material and the
repository's existing naming style.

## Goal

When the user submits an image of an exercise, create the relevant C++ files in
the correct chapter/exercise location, build the program, run it, and leave the
user with a clear way to test it.

## Problem Intake

- Read the exercise image and identify the chapter number, exercise number,
  required classes, required functions, and sample input/output.
- Do not copy long textbook problem statements into repository files. Summarize
  only what is necessary to implement and test the solution.
- If the image does not show the chapter or exercise number, inspect nearby
  repository conventions and ask the user for the missing number before creating
  files.
- If the image is ambiguous, state the assumption in the final response.

## Chapter And File Locations

- Chapter directories use two digits: `chapter_01`, `chapter_02`, ...,
  `chapter_14`.
- For Chapter 13 and later work, create one directory per exercise:
  `chapter_XX/exerciseXX_N/`.
- Name the main program after the exercise directory:
  `chapter_XX/exerciseXX_N/exerciseXX_N.cpp`.
- Put each class in matching files named after the class:
  `ClassName.h` and `ClassName.cpp`.
- Once a concept has been introduced in an earlier chapter, use it in later
  chapters when it improves structure. In particular, Chapter 13 and later
  exercises should use small classes split into `.h` and `.cpp` files instead
  of placing all logic in `main`.
- Use pointers and dynamic arrays where they are a natural fit for the exercise,
  following the Chapter 11 style with constructors, destructors, and `delete[]`.
  Do not force pointers into places where a simple local variable is clearer.
- If an exercise is a simple standalone program and the existing chapter uses
  single-file solutions, follow the local chapter convention.
- Keep supporting files inside the exercise directory unless the chapter already
  has shared headers for that topic.

Example for Exercise 14.3:

```text
chapter_14/exercise14_3/
  exercise14_3.cpp
  Rational.h
  Rational.cpp
```

## Language Constraints

- Use only C++ tools, syntax, library features, functions, and techniques that
  have appeared in the current or earlier chapters.
- Do not use later-language conveniences just because they are available.
- Prefer the style already used in nearby exercises over modernizing the code.
- If a problem is from Chapter 14, Chapter 14 material is allowed, but Chapter 15
  or later concepts are not.
- Avoid adding abstractions that are not requested by the exercise.

## Implementation Rules

- Keep code readable and suitable for someone learning from the archive.
- Use include guards in every header.
- Split class declarations into `.h` files and definitions into `.cpp` files.
- Keep `main` in the exercise file, not in class implementation files. For
  Chapter 13 and later, `main` should usually just create the exercise class and
  call a `run` or similarly named method.
- Match exact output when the image shows required output.
- Preserve user changes and unrelated work in the repository.

## Test Data And File Exercises

- For file I/O exercises, bundle small local test input files in the exercise
  folder so the program can be built and run without external downloads.
- Treat generated outputs such as copied files, split pieces, `.new` files, and
  most `.dat` files as build/run artifacts rather than source files.
- Commit a generated binary fixture only when a later exercise explicitly
  depends on that file to run, such as a restore/read exercise.
- For binary copy, split, combine, encryption, and object-storage exercises, use
  binary file I/O with `read`, `write`, `get`, or `put` as appropriate.

## Docker Builds

- Use the single root `Dockerfile` for the whole project.
- Do not add per-exercise Dockerfiles.
- Build one exercise by passing its folder as `TARGET` from the repository root:

  ```powershell
  docker build --build-arg TARGET=chapter_13/exercise13_1 -t exercise13_1 .
  ```

- Run the image normally for read-only tests:

  ```powershell
  docker run --rm -it exercise13_1
  ```

- For exercises that create or modify files, mount the exercise folder into the
  target work directory so file changes are visible on the host:

  ```powershell
  docker run --rm -it --mount "type=bind,source=${PWD}\chapter_13\exercise13_1,target=/workspace/chapter_13/exercise13_1" exercise13_1
  ```

## Build And Run Workflow

After creating or editing files:

1. Build from the exercise directory with local `g++` when available:

   ```powershell
   g++ -std=c++17 -O2 *.cpp -o exerciseXX_N.exe
   ```

2. If local `g++` is unavailable, build with Docker from the repository root:

   ```powershell
   docker build --build-arg TARGET=chapter_XX/exerciseXX_N -t exerciseXX_N .
   ```

3. Run the program:

   ```powershell
   .\exerciseXX_N.exe
   ```

   or, for Docker:

   ```powershell
   docker run --rm -it exerciseXX_N
   ```

4. For interactive programs, run at least one representative test. Then provide
   the exact command the user can run to test it manually.

5. If the environment cannot build or run the program, explain the blocker
   precisely, such as missing `g++` or Docker Desktop not running.

## Final Response Checklist

The final response should include:

- Files created or changed.
- Build command used and whether it succeeded.
- Run command used and notable output.
- Any assumption made from the submitted image.
- The exact command for the user to run their own test.
