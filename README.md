# Project: Simple Shell (hsh)

## 📝 Description
This project is a custom implementation of a Unix Command Line Interpreter. It was developed as a collaborative project at Holberton School, focusing on deep-level C programming, system calls, process management, and rigorous memory handling.

The goal was to recreate the core logic of a shell (like sh or bash), capable of reading user input, parsing it into commands and arguments, resolving the PATH, and executing programs using child processes. This project demonstrates our ability to build a low-level tool that interacts directly with the Linux kernel.

### 👥 Collaborative Work

This repository is the result of a joint effort between Hugo and Pierre, where we shared responsibilities:
* Architecture & Flowchart design: Defining the interaction between the main loop, the parser, and the executor.
* Path Resolution: Implementing the logic to search and validate executable commands in the environment.
* Memory Management: Ensuring a "leak-free" implementation, even in cases of command failure or signals.
* Process Control: Managing the life cycle of processes using fork, execve, and wait.

## 📋 Requirements
Environment
* **Operating System:** Ubuntu 20.04 LTS
* **Compiler:** `gcc`
* **C Standard:** `gnu89` (compiled with flags `-Wall -Werror -Wextra -pedantic -std=gnu89`)

### Authorized Functions & Macros
The following functions and macros from the standard library are used in this project:

|`access`|	
|`execve`|	
|`exit`|	
|`fork`|	
|`free`|	
|`getline`|
|`isatty`|	
|`malloc`|
|`perror`|	
|`stat`|	
|`strtok`|	
|`wait`|	
|`waitpid`|
|`write`|
|`_exit`|
|`signal`|

## 📂 Project Structure

| File | Description |
| :---: | :--- |
|`main.c`|	Entry point of the shell. Manages the REPL (Read-Eval-Print Loop). |
|`shell.h`|	Header file with guards, library inclusions, and function prototypes. |
|`parser.c`|	Handles line reading and tokenization (splitting the input into argv). |
|`executor.c`|	Core system logic: manages fork, execution via execve, and waiting. |
|`path.c`|	Locates the command by searching through the PATH environment variable. |
|`builtins.c`|	Handles internal shell commands like exit and env. |
|`utils.c`|	Helper functions for memory cleanup and error formatting. |
|`AUTHORS.md`| Author file for project contributors. |

## ⚙️ How it works (The Flow)
The shell operates through a continuous cycle often called REPL:
* Read: The shell displays a prompt and reads the user's input.
* Parse: The input string is broken down into tokens (command + arguments).
* Check: It checks if the command is a "Built-in". If so, it's executed immediately.
* Resolve: If not a built-in, it searches for the executable in the PATH folders.
* Execute: It forks a child process. The child runs the command while the parent waits.
* Free: All temporary memory is cleared before starting the next cycle.

## Flowchart
The following diagram describes the logic of the `Simple_Shell` function:

<img width="2239" height="3045" alt="Image" src="https://github.com/user-attachments/assets/181cf82c-f8b5-4b6e-b77e-142c9fda1c60" />

## 🚀 Getting Started

1. Installation

Clone the repository using Git:
```bash
git clone https://github.com/Pierre1200/holbertonschool-shell.git
```

2. Compilation
Compile all source files using the standard flags:

```Bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Usage  
The shell supports both interactive and non-interactive modes.

1. Interactive Mode:

```Bash
./hsh
($) /bin/ls
file1  file2  hsh
($) exit
```

2. Non-interactive Mode:
```Bash
echo "/bin/ls" | ./hsh
```

## 🛡️ Memory Check (Valgrind)
Our implementation has been strictly tested to ensure zero memory leaks. Every allocated block is tracked and freed properly, ensuring the shell can run indefinitely without consuming extra system resources.

Command:
```Bash
valgrind --leak-check=full --show-leak-kinds=all ./hsh
```

Output:
```Bash
==40506== HEAP SUMMARY:
==40506==     in use at exit: 0 bytes in 0 blocks
==40506==   total heap usage: 24 allocs, 24 frees, 5,155 bytes allocated
==40506== 
==40506== All heap blocks were freed -- no leaks are possible
==40506== 
==40506== For lists of detected and suppressed errors, rerun with: -s
==40506== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

✍️ Authors
Lacassagne Hugo - GitHub Profile
Rouvellat Pierre - GitHub Profile


