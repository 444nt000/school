#include "check.h"

/*
** Buffers are pre-filled with '#'. After the call, every byte at or past
** `size` (and past dst's own content) must still be '#': that is how an
** overflow gets caught instead of silently passing.
*/

#define CAP 32

static void	fill(char *buf, const char *init)
{
	memset(buf, '#', CAP);
	buf[CAP - 1] = '\0';
	memcpy(buf, init, strlen(init) + 1);
}

static void	one(const char *dst, const char *src, size_t size)
{
	char	mine[CAP];
	char	theirs[CAP];
	size_t	i;

	fill(mine, dst);
	fill(theirs, dst);
	CHECK_INT(ft_strlcat(mine, src, size), strlcat(theirs, src, size));
	if (memcmp(mine, theirs, CAP))
		FAIL("strlcat(\"%s\", \"%s\", %zu): got \"%s\", expected \"%s\"", dst,
			src, size, mine, theirs);
	i = size;
	if (i < strlen(dst) + 1)
		i = strlen(dst) + 1;
	while (i < CAP - 1)
		if (mine[i++] != '#')
			FAIL("strlcat(\"%s\", \"%s\", %zu) wrote past size", dst, src,
				size);
}

int	main(void)
{
	one("", "", 10);
	one("abc", "", 10);
	one("", "abc", 10);
	one("foo", "bar", 10);
	one("foo", "bar", 7);
	one("foo", "bar", 6);
	one("foo", "bar", 4);
	one("foo", "bar", 3);
	one("foo", "bar", 1);
	one("foo", "bar", 0);
	one("hello", "world", 8);
	one("12345678", "9", 9);
	return (done("ft_strlcat"));
}
