#include "check.h"

static int	sign(int n)
{
	return ((n > 0) - (n < 0));
}

static void	one(const void *s1, const void *s2, size_t n)
{
	int	got;
	int	want;

	got = ft_memcmp(s1, s2, n);
	want = memcmp(s1, s2, n);
	if (sign(got) != sign(want))
		FAIL("ft_memcmp(%p, %p, %zu) = %d, expected %d", s1, s2, n, got, want);
}

int	main(void)
{
	unsigned char	a[] = {0, 1, 2, 255, 128, 0, 42};
	unsigned char	b[] = {0, 1, 2, 255, 128, 0, 43};
	unsigned char	c[] = {0, 1, 3, 0, 0, 0, 0};
	unsigned char	d[] = {255, 0};
	unsigned char	e[] = {1, 0};

	one("abc", "abc", 3);
	one("abc", "abd", 3);
	one("abd", "abc", 3);
	one("abc", "abd", 2);
	one("abc", "xyz", 0);
	one("abcdef", "abcxyz", 3);
	one("abcdef", "abcxyz", 4);
	one("a", "b", 1);
	one("b", "a", 1);
	one("ab", "ac", 2);
	one("ac", "ab", 2);
	one("abc\0def", "abc\0xyz", 7);
	one("abc\0def", "abc\0xyz", 4);
	one(a, a, 7);
	one(a, b, 6);
	one(a, b, 7);
	one(b, a, 7);
	one(a, c, 7);
	one(c, a, 7);
	one(d, e, 1);
	one(e, d, 1);
	one("\x80", "\x7f", 1);
	one("A", "a", 1);
	return (done("ft_memcmp"));
}
