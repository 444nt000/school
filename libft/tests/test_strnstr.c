#include "check.h"

/* glibc has no strnstr (it's BSD-only); reference impl for comparison. */
static const char	*ref_strnstr(const char *big, const char *little,
		size_t len)
{
	size_t	little_len;
	size_t	i;

	little_len = strlen(little);
	if (little_len == 0)
		return (big);
	i = 0;
	while (i + little_len <= len && big[i])
	{
		if (strncmp(big + i, little, little_len) == 0)
			return (big + i);
		i++;
	}
	return (NULL);
}

static void	one(const char *big, const char *little, size_t len)
{
	const char	*got;
	const char	*want;

	got = ft_strnstr(big, little, len);
	want = ref_strnstr(big, little, len);
	if (got != want)
		FAIL("ft_strnstr(\"%s\", \"%s\", %zu) = %p, expected %p", big, little,
			len, got, want);
}

int	main(void)
{
	one("hello world", "world", 11);
	one("hello world", "xyz", 11);
	one("hello", "", 5);
	one("", "a", 5);
	one("", "", 5);
	one("hello", "hello", 0);
	one("hello world", "world", 7);
	one("hello world", "world", 10);
	one("hi", "hi", 100);
	one("exact", "exact", 5);
	one("aaaaab", "aab", 6);
	one("abcdef", "def", 6);
	return (done("ft_strnstr"));
}
