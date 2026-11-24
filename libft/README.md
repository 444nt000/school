*This activity has been created as part of the 42 curriculum by aradix.*

# Libft

# Description

A reimplementation of some libc functions with extra functions (split, trim, itoa, linked lists, ...).
Pedagogical purpose, the goal is to understand how things work under the hood and having a toolbox to reuse in future projects.

# Instructions

First, compile the library into `libft.a` by running:
```bash
make
```
Then you can use `libft.a` in your own project by including the header in
your file:
```c
#include "libft.h"
```

And compile your program with:

```bash
cc main.c libft.a
```

# Library content

The library is split into three parts, as asked by the subject.

## Part 1 - Libc functions

- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`:
  character classification.
- `ft_toupper`, `ft_tolower`: character case conversion.
- `ft_strlen`: length of a string.
- `ft_memset`, `ft_bzero`: fill a memory zone.
- `ft_memcpy`, `ft_memmove`: copy a memory zone (`ft_memmove` handles
  overlapping zones).
- `ft_strlcpy`, `ft_strlcat`: copy/concatenate strings with a size limit.
- `ft_strchr`, `ft_strrchr`: find a character in a string.
- `ft_strncmp`: compare two strings.
- `ft_memchr`, `ft_memcmp`: find/compare raw memory.
- `ft_strnstr`: find a substring in a string.
- `ft_atoi`: convert a string to an int.
- `ft_calloc`, `ft_strdup`: allocate memory / duplicate a string.

## Part 2 - Additional functions

- `ft_substr`: extract part of a string.
- `ft_strjoin`: concatenate two strings into a newly allocated one.
- `ft_strtrim`: remove given characters from both ends of a string.
- `ft_split`: split a string into an array of strings using a delimiter.
- `ft_itoa`: convert an int to a newly allocated string.
- `ft_strmapi`: apply a function to each character of a string and return
  the result as a new string.
- `ft_striteri`: apply a function to each character of a string, in place.
- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`: output a
  char/string/string with newline/int to a file descriptor.

## Part 3 - Linked list

- `ft_lstnew`: create a new node.
- `ft_lstadd_front`, `ft_lstadd_back`: add a node at the start/end of a
  list.
- `ft_lstsize`: count the nodes of a list.
- `ft_lstlast`: get the last node of a list.
- `ft_lstdelone`: free one node and its content.
- `ft_lstclear`: free a whole list and its content.
- `ft_lstiter`: apply a function to the content of each node.
- `ft_lstmap`: build a new list by applying a function to each node's
  content.

# Resources

- [File descriptor](https://www.computerhope.com/jargon/f/file-descriptor.htm)
- [Data structure alignment](https://www.geeksforgeeks.org/c/structure-member-alignment-padding-and-data-packing/)
- [Restrict keyword](https://en.wikipedia.org/wiki/Restrict)
- [Linking in C](https://averyv.me/blog/linking-by-example/)
- [Create static library](https://lindevs.com/create-static-library-from-object-files-on-linux)
