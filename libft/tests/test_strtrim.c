#include "check.h"

static void	one(const char *s1, const char *set, const char *want)
{
	char	*got;

	got = ft_strtrim(s1, set);
	CHECK_STR(got, want);
	free(got);
}

int	main(void)
{
	one("  hello  ", " ", "hello");
	one("xxhelloxx", "x", "hello");
	one("hello", "x", "hello");
	one("", "x", "");
	one("xxx", "x", "");
	one("x", "x", "");
	one(" ", " ", "");
	one("abc", "abc", "");
	one("  a  ", " ", "a");
	one("xyhelloyx", "xy", "hello");
	one("hello", "", "hello");
	one("", "", "");
	one("abcba", "ab", "c");
	CHECK(ft_strtrim(NULL, "x") == NULL);
	CHECK(ft_strtrim("abc", NULL) == NULL);
	return (done("ft_strtrim"));
}
