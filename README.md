# 42 Cursus' get_next_line(GNL)

##### ***Reading a line from a fd is way too tedious\***

![](C:\Users\dellh\OneDrive\Imagens\get_next_linem.png)

##  Status

 **Finished**

Grade: **125/100** ✅

## 💡 About the project

> The 42 school's get_next_line project is where we learn to read from a file descriptor, as well as the use of static variables.
>
> This function returns a single line from a given file descriptor. If called in a loop, get_next_line returns the entire contents of a file, line by line until it reaches the end of the file. It can be compiled specifying any buffer size.

## 🛠️ Usage

This function is not a stand-alone program, its files must be included and compiled within another project.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```c
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```sh
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

## 📋 Testing

You only have to edit the get_next_line.c file and uncomment the main function and headers inside it. You can edit test.txt files to put another text if you wish to test othe cases. Then simply run this command (change "< size >" with desired buffer size) :

```sh
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c && ./a.out
```

Or you can use any of this third party testers to test the project

- [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester)

