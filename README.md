
# getnextline

## Introduction

`getnextline` is a utility function written in C, designed to read a line from a given file descriptor every time it is called, until the end of the file. This function is especially useful for reading and processing files line by line. The implementation showcases handling of dynamic memory allocation and static variables in C to maintain the read state between function calls.

## Project Description

The primary objective of `getnextline` is to offer a straightforward and efficient method for sequential line reading from files or input streams. This project is an excellent demonstration of fundamental C programming concepts, including memory management, file operations, and efficient string handling.

### Features

- Dynamically reads and returns the next line from a file descriptor on each call.
- Handles lines of any length with efficient memory usage.
- Can be integrated into various C projects that require reading from files or input streams line by line.

## Getting Started

### Prerequisites

To use `getnextline` in your project, you need:

- A C compiler (GCC or Clang recommended)
- Basic understanding of C programming and file I/O operations

### Setup

1. Clone or download the `getnextline` source code into your project directory.

2. Include the `get_next_line.h` header file in your C files where you intend to use the `getnextline` function.

### Implementing Your Main Function

Since `getnextline` does not come with a main function, you will need to implement your own. Here's a simple example of how to use `getnextline` to read from a file:

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
```
This example demonstrates how to open a file, read lines one by one using `getnextline`, and print each line to the standard output until the end of the file is reached.

### Compilation

Compile your project along with `get_next_line.c` and `get_next_line_utils.c` files. For example:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c your_main_file.c -o your_program_name
```

Replace `your_main_file.c` with the name of your C file that contains the main function, and `your_program_name` with the desired name for the compiled executable.
