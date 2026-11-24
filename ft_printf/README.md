*This activity has been created as part of the 42 curriculum by aradix.*

# Description

A reimplementation of the libc `printf()`, as static library `libftprintf.a`.
Pedagogical purpose, the goal is to learn how variadic functions work in C (`va_start`, `va_arg`, `va_end`).

`ft_printf()` writes its format string to the standard output, replacing each conversion with the matching argument.
It returns the number of characters printed, or `-1` on error.

Supported conversions:

- `%c`: a single character.
- `%s`: a string (`(null)` for a `NULL` string).
- `%p`: a `void *` pointer in lowercase hexadecimal, prefixed with `0x`
  (`(nil)` for a `NULL` pointer).
- `%d`, `%i`: a signed decimal int.
- `%u`: an unsigned decimal int.
- `%x`, `%X`: an unsigned int in lowercase/uppercase hexadecimal.
- `%%`: a percent sign.

As asked by the subject, there is no buffer management: each character is directly printed  with `write()`.

# Instructions

First, compile the library into `libftprintf.a` by running:
```bash
make
```
Then you can use it in your own project by including the header in your file:
```c
#include "ft_printf.h"

ft_printf("%s is %d, lives at %p\n", "Bob", 42, &bob);
```

And compile your program with:
```bash
cc -Iheaders main.c libftprintf.a
```

# Algorithm and data structures

## Main loop

`ft_printf()` walks the format string one character at a time:

- a normal character is written as is;
- a `%` means the next character is a conversion, handled by `print_conv()`.

The return value of each write is added to a counter. As soon as a write fails
(`-1`), the loop stops and `ft_printf()` returns `-1`.

## Dispatch table

Each conversion has its own handler function. They are stored in a static
table of `t_conv`, a struct holding a conversion character and a function pointer:
```c
{'c', handle_char}, {'s', handle_str}, {'p', handle_ptr}, ...
```

Why a table instead of a chain of `if` / `else if`:

- adding a conversion is one line in the table plus one handler;
- each handler stays small, in its own file under `handlers/`, which keeps
  every function within the norm limits.

## Argument union

`va_arg()` has to know the type of the argument it reads. For the mandatory conversions there are only two:

- an `int` for `%c`, `%d`, `%i`, `%u`, `%x` and `%X` (a `char` is promoted to `int` when passed to a variadic function, and an `unsigned int` has the same size as an `int`);
- a pointer for `%s` and `%p`.

## Edge cases

- `%s` with `NULL` prints `(null)` and `%p` with `NULL` prints `(nil)`, like
  the glibc `printf()` on Linux.
- A `NULL` format, an unknown conversion (`%y`) or a `%` at the end of the
  format returns `-1`. These are undefined behaviors in the C standard.
- Flags and width (`%5d`) are not asked by the subject and also return `-1`.

# Resources

- `man 3 printf`, `man 3 stdarg`, `man 3 va_arg`
- [Variadic functions](https://en.cppreference.com/w/c/variadic)
- [printf format specification](https://en.cppreference.com/w/c/io/fprintf)
