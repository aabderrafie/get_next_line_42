
# Get Next Line

## Overview

**Get Next Line** is a function that simplifies the process of reading a line from a file descriptor. This project focuses on creating a function that reads from a file descriptor one line at a time, handling various edge cases and providing robust functionality.

## Mandatory Part

### Function Name
`get_next_line`

### Prototype
```c
char *get_next_line(int fd);
```

### Turn-in Files
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

### Parameters
- `fd`: The file descriptor to read from.

### Return Value
- **Read line**: On successful read.
- **NULL**: When there is nothing else to read, or an error occurred.

### External Functions
- `read`
- `malloc`
- `free`

### Description
Write a function that returns a line read from a file descriptor.

- Repeated calls to `get_next_line()` should read the text file pointed to by the file descriptor, one line at a time.
- The function should return the line that was read. If there is nothing else to read or if an error occurred, it should return `NULL`.
- Ensure the function works as expected when reading both from a file and from standard input.
- The returned line should include the terminating `\n` character, except if the end of the file was reached and it does not end with a `\n` character.
- Your header file `get_next_line.h` must contain the prototype of the `get_next_line()` function.
- Add all necessary helper functions in the `get_next_line_utils.c` file.
- Utilize a static variable for maintaining state between function calls.

### Compilation
Since `get_next_line()` requires reading files, add this option to your compiler call: `-D BUFFER_SIZE=n`. This defines the buffer size for `read()`. The buffer size will be modified by peer evaluators and the Moulinette to test your code.

- Compile the project with and without the `-D BUFFER_SIZE` flag:
  ```sh
  cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
  ```

### Undefined Behavior
- `get_next_line()` has undefined behavior if the file pointed to by the file descriptor changes between calls and `read()` hasn't reached the end of the file.
- Reading a binary file with `get_next_line()` has undefined behavior. You may implement a logical way to handle this if desired.

### Constraints
- Do not read the whole file and then process each line. Read as little as possible each time `get_next_line()` is called. Return the current line upon encountering a newline character.
- Forbidden functions:
  - `lseek()`
  - Global variables
- You are not allowed to use your libft in this project.

## Bonus Part

This project is straightforward and doesn’t allow for complex bonuses. However, if you have completed the mandatory part, you can attempt the following bonus requirements:

### Bonus Requirements
- Develop `get_next_line()` using only one static variable.
- `get_next_line()` should manage multiple file descriptors simultaneously. You should be able to read from different file descriptors per call without losing the reading thread of each file descriptor or returning a line from another file descriptor.

### Bonus Turn-in Files
In addition to the mandatory part files, you will turn in the following files:
- `get_next_line_bonus.c`
- `get_next_line_bonus.h`
- `get_next_line_utils_bonus.c`

## Installation

Clone the repository and navigate to the project directory:

```sh
git clone https://github.com/aabderrafie/get_next_line_42_Cursus.git
cd get_next_line
```

Compile the project:

```sh
make
```

## Usage

Include the `get_next_line` header and link the library in your project:

```c
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

Compile your project with the necessary files:

```sh
gcc -o my_program my_program.c get_next_line.c get_next_line_utils.c -I.
```

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgements

Special thanks to the 42 Network and all the peer reviewers who helped make this project a success.

