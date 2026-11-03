#include "check.h"

static void	one(const char *s, unsigned int start, size_t len, const char *want)
{
	char	*got;

	got = ft_substr(s, start, len);
	CHECK_STR(got, want);
	free(got);
}

int	main(void)
{
	char	*res;

	one("hello world", 6, 5, "world");
	one("hello", 0, 3, "hel");
	one("hello", 1, 0, "");
	one("hello", 2, 100, "llo");
	one("hello", 10, 5, "");
	one("hello", 5, 5, "");
	one("", 0, 5, "");
	one("hello", 0, 5, "hello");
	one("hello", (unsigned int)-1, 5, "");
	res = ft_substr("hello world", 0, 5);
	CHECK_INT(res[5], '\0');
	free(res);
	return (done("ft_substr"));
}
