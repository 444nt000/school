*This activity has been created as part of the 42 curriculum by aradix.*

# Description

A function that returns one line read from a file descriptor, or `NULL` at end of file or on
error. Repeated calls read the whole file, one line at a time.

The returned line includes its `\n`, except for a last line that doesn't end with one.

`read()` doesn't care about lines, so a read usually stops mid-line or grabs several at once.
What has been read but not returned yet is kept in a static buffer between calls.
Works on files and on standard input.

# Instructions

```bash
# note: -D is optional, BUFFER_SIZE defaults to 200
cc -Wall -Wextra -Werror main.c get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=42

int   fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)))
{
    printf("%s", line);
    free(line);
}
close(fd);
```
The caller frees each returned line.

# Resources

- `man 2 open`, `man 2 read`
