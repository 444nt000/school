#include "check.h"

static int	sign(int n)
{
	return ((n > 0) - (n < 0));
}

static void	one(const char *s1, const char *s2, size_t n)
{
	int	got;
	int	want;

	got = ft_strncmp(s1, s2, n);
	want = strncmp(s1, s2, n);
	if (sign(got) != sign(want))
		FAIL("ft_strncmp(\"%s\", \"%s\", %zu) = %d, expected %d", s1, s2, n,
			got, want);
}

int	main(void)
{
	one("abc", "abc", 3);
	one("abc", "abc", 10);
	one("abc", "abd", 3);
	one("abd", "abc", 3);
	one("abc", "abd", 2);
	one("abc", "abd", 0);
	one("abc", "xyz", 0);
	one("abc", "ab", 3);
	one("ab", "abc", 3);
	one("abc", "ab", 2);
	one("", "", 5);
	one("", "a", 1);
	one("a", "", 1);
	one("a", "b", 1);
	one("b", "a", 1);
	one("abc\0xyz", "abc\0abc", 7);
	one("test\0", "test", 5);
	one("a", "a", (size_t)-1);
	one("\xff", "a", 1);
	one("a", "\xff", 1);
	one("\x80", "\x7f", 1);
	one("abc\xff", "abc\x01", 4);
	one("A", "a", 1);
	one("hello", "help", 4);
	one("hello", "help", 3);
	return (done("ft_strncmp"));
}
