# My C++ Solutions

This repository began as my solutions to the exercises in *Introduction to Programming with C++ (3rd Edition) International Edition* by Y. Daniel Liang. It now documents the transition from solving those book-based problems to crafting high-quality prompts for Codex, OpenAI's code generation model.

Starting from **Chapter 12**, I switched to AI-assisted solutions: each exercise is driven by a Codex-style prompt followed by AI-generated C++ code. Earlier chapters contain hand-written solutions created while progressing through the book, sticking to the rule that no syntax is used before it appears in the text. The original problem statements are not included here due to copyright restrictions.

I am learning this as a hobby, so updates are not regular.

## Building Exercises

To build native Windows executables for the class-based exercise folders, run:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\build_exercise_exes.ps1
```

The script builds Chapter 13 through Chapter 19 exercise folders by default and
writes an `exerciseXX_N.exe` file inside each exercise directory. The generated
`.exe` files are ignored by git and are only for local testing. If `g++` is not
on `PATH`, pass the compiler explicitly:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\build_exercise_exes.ps1 -Compiler C:\MinGW\bin\g++.exe
```

This project uses one root Dockerfile for exercise builds. Pass the exercise
folder as `TARGET`:

```powershell
docker build --build-arg TARGET=chapter_13/exercise13_21 -t exercise13_21 .
docker run --rm -it exercise13_21
```

For exercises that write files, mount the exercise folder when running so output
files are written back to the working tree.

## Using This Project with Codex

1. Each chapter directory from Chapter 12 onward contains a `prompt.md` describing the problem.
2. Provide the prompt to Codex and let it generate an initial C++ solution.
3. Review, run, and refine the generated code.
4. Commit both the prompt and the final code so readers can see the prompt-response pair.

## Contributor Guidelines

If you'd like to contribute:

- Write prompts in Markdown with a clear title, description, constraints, and sample I/O.
- Place prompts and generated solutions in the appropriate chapter directory.
- Keep prompts and solutions in separate blocks and note any manual edits made to the AI-generated code.

## Completed Solutions

- [Chapter 1](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_01): Introduction to Computers, Programs and C++ _(8th May 2021)_
- [Chapter 2](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_02): Elementary Programming _(19th May 2021)_
- [Chapter 3](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_03): Selections _(23rd May 2021)_
- [Chapter 4](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_04): Mathematical Functions, Characters and Strings _(30th May 2021)_
- [Chapter 5](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_05): Loops _(18th June 2021)_
- [Chapter 6](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_06): Functions _(23rd June 2021)_
- [Chapter 7](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_07): Single-Dimensional Arrays and C-Strings _(3rd September 2021)_
- [Chapter 8](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_08): Multidimensional Arrays _(02nd February 2022)_
- [Chapter 9](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_09): Objects and Classes _(04th February 2022)_
- [Chapter 10](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_10): Object-Oriented Thinking _(13th March 2022)_
- [Chapter 11](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_11): Pointers and Dynamic Memory Management _(24th March 2022)_
- [Chapter 12](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_12): Templates, Vectors and Stacks _(AI-assisted with Dockerized builds, completed 10th December 2025)_
- [Chapter 13](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_13): File Input/Output _(AI-assisted, class-based exercise folders with bundled test files, completed 29th May 2026)_
- [Chapter 14](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_14): Operator Overloading and Templates _(AI-assisted, class-based exercise folders built through the root Dockerfile, completed 29th May 2026)_
- [Chapter 15](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_15): Inheritance and Polymorphism _(AI-assisted, class-based exercise folders built through the root Dockerfile; exercises 15.1-15.5 completed 29th May 2026)_
- [Chapter 16](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_16): Exception Handling _(AI-assisted, class-based exercise folders built through the root Dockerfile; exercises 16.1-16.9 completed 27th June 2026)_
- [Chapter 17](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_17): Recursion _(AI-assisted, class-based exercise folders built through the root Dockerfile; exercises 17.1-17.24 completed 29th May 2026)_
- [Chapter 18](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_18): Developing Efficient Algorithms _(AI-assisted, class-based exercise folders built through the root Dockerfile; exercises 18.1-18.15 completed 30th May 2026)_
- [Chapter 19](https://github.com/Kevin-Oudai/my_cpp_solutions/tree/main/chapter_19): Sorting _(AI-assisted from a full chapter PDF, class-based exercise folders built through the root Dockerfile; exercises 19.1-19.9 completed 27th June 2026)_
