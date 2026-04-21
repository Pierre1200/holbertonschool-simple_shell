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
* **Compiler:** `gcc` or `make`
* **C Standard:** `gnu89` (compiled with flags `-Wall -Werror -Wextra -pedantic -std=gnu89`)

### 📚 Authorized Functions & Macros

| Function | Description | Function | Description |
| :--- | :--- | :--- | :--- |
| `access` | Check permissions | `stat` | Get file status |
| `execve` | Execute program | `strtok` | Tokenize strings |
| `fork` | Create child process | `wait` | Wait for process |
| `free` | Release memory | `write` | Output to stream |
| `getline` | Read input line | `_exit` | Terminate process |
| `malloc` | Allocate memory | `signal` | Handle signals |

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
|`Makefile`|	Build script to automate the compilation process. |
|`hsh.1`|	Manual page (manpage) explaining how to use the shell. |
|`.gitignore`|	Specifies files and directories to be ignored by Git. |
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

2. Compilation & Usage

This project includes a **Makefile** to automate the build process. This ensures the shell is compiled with the required flags for the Holberton School standards.

### 1. Build Instructions

To compile the shell, navigate to the project root and use the following commands:

| Command | Description |
| :--- | :--- |
| `make` | Compiles all source files and generates the `hsh` executable. |
| `make clean` | Removes object files (`.o`) to clean up the workspace. |
| `make fclean` | Removes both object files and the `hsh` executable. |
| `make re` | Recompiles the entire project from scratch (`fclean` + `make`). |

you can also use :
```Bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c shell.h builtins.c executor.c utils.c path.c parser.c -o hsh
```

### 2. Running the Shell

1. Once compiled, you can launch the shell in two different modes:

**Interactive Mode** (like a real terminal):
```Bash
./hsh
($) /bin/ls
file1  file2  hsh
($) exit
```

2. Non-interactive Mode: (without compilation)
```Bash
echo "/bin/ls" | ./hsh
```

## 📖 Documentation
The project includes a custom manual page for hsh, following the standard Linux programmer's manual format (man page). It provides a detailed technical description of the shell's behavior, including its execution flow, built-in commands, and environment handling.

How to access the manual
To view the manual page and learn more about the shell's features, run the following command from the root of the repository:

```Bash
man ./hsh.1
```

<img width="1223" height="801" alt="image" src="https://github.com/user-attachments/assets/7687228a-e193-456f-8613-3aa1dd32a459" />

## 🛡️ Memory Check (Valgrind)

Our implementation has been strictly tested to ensure zero memory leaks. Every allocated block is tracked and freed properly, ensuring the shell can run indefinitely without consuming extra system resources.

Command:
```Bash
valgrind --leak-check=full --show-leak-kinds=all ./hsh
```

Output:
```Bash
==66377== HEAP SUMMARY:
==66377==     in use at exit: 0 bytes in 0 blocks
==66377==   total heap usage: 26 allocs, 26 frees, 5,787 bytes allocated
==66377==
==66377== All heap blocks were freed -- no leaks are possible
==66377==
==66377== For lists of detected and suppressed errors, rerun with: -s
==66377== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## ✍️ Authors

* **Rouvellat Pierre** - [GitHub Profile](https://github.com/Pierre1200)
* **Lacassagne Hugo** - [GitHub Profile](https://github.com/Hugol4ka)


