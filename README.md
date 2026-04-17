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

you can use too :
```Bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 main.c shell.h builtins.c executor.c utils.c path.c parser.c -o hsh
```

### 2. Running the Shell

Once compiled, you can launch the shell in two different modes:

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

## 🔍 IA Code Review

To ensure the highest code quality and robustness, this project underwent an AI-assisted review focusing on:
* **Memory Safety:** Double-checking allocation/deallocation patterns.
* **Edge Case Handling:** Validating behavior with empty inputs, long paths, and signals.
* **Logic Optimization:** Streamlining the path resolution and command execution flow.
```Bash
* Robust Path Resolution: The find_path function effectively handles environment parsing with careful memory management, ensuring no leaks occur during string tokenization of the PATH.  

* Process Life Cycle: The execution flow correctly implements the fork-execve-wait pattern, providing a stable environment for running external commands.  

* Memory Integrity: The shell maintains a clean heap across multiple execution cycles. The "Read-Eval-Print Loop" (REPL) ensures that all temporary buffers are freed before the next prompt.  

* Edge Case Resilience: The parser safely handles empty inputs and excessive whitespace, preventing segmentation faults or unintended command executions.
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

## ✍️ Authors

* **Rouvellat Pierre** - [GitHub Profile](https://github.com/Pierre1200)
* **Lacassagne Hugo** - [GitHub Profile](https://github.com/Hugol4ka)


