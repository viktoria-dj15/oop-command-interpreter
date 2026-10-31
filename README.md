# OOP Command Interpreter

A C++ command-line interpreter developed as a 2025 Object-Oriented Programming course project.

## Features

- Commands: `echo`, `prompt`, `time`, `date`, `touch`, `rm`, `truncate`, `wc`, `tr`, `head`, and `batch`.
- Command pipelines with `|`.
- Input redirection with `<`, output redirection with `>`, and append with `>>`.
- Quoted text arguments, file input, and batch scripts.
- A lexer, command factory, polymorphic command hierarchy, and custom exception types.

## Build and run

The original implementation targets Windows and uses `localtime_s`.
With a MinGW-w64 C++ compiler, run from the repository directory:

```sh
g++ -std=c++17 *.cpp -o interpreter.exe
./interpreter.exe
```

Alternatively, use CMake with your installed Windows C++ toolchain:

```sh
cmake -S . -B build
cmake --build build --config Release
```

The executable is placed in `build` (or `build/Release` for multi-configuration generators). Run it with the repository directory as the working directory to use the included sample files.

## Examples

Enter these at the interpreter prompt:

```text
echo "Hello World!"
echo "Hello World!" | wc -w
echo "Hello" > greeting.txt
echo < greeting.txt
time
date
batch red_commands.txt
```

The `.txt` files are the original sample inputs, command scripts, and output snapshots. Some scripts create, overwrite, or remove files in the current working directory.

## Design

`Main.cpp` starts the singleton `Interpreter`. `Lexer` tokenizes each line; `Factory` constructs commands and a `Pipe`. Concrete commands implement the abstract `Command` interface, with shared file and redirection behavior in base classes. `Pipe` passes command output to the next command and handles final output redirection.

## Project status

This repository preserves the coursework implementation. Publication adds this README, CMake configuration, and a `.gitignore`, plus explicit `<ctime>` includes in `Date.h` and `Time.h` needed to compile with MinGW-w64.

Known limitations: no built-in `exit` command; stop the interactive program with Ctrl+C. End-of-input is not handled by the prompt loop. A command error can terminate the session, and argument validation and ownership through raw pointers need further hardening. This is an educational interpreter, not a general-purpose operating-system shell.
