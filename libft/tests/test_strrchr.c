#include "check.h"

static void	one(const char *s, int c)
{
	const char	*got;
	const char	*want;

	got = ft_strrchr(s, c);
	want = strrchr(s, c);
	if (got != want)
		FAIL("ft_strrchr(\"%s\", %d) = %p, expected %p", s, c, got, want);
}

int	main(void)
{
	char	str[] = "hello world";
	int		c;

	one(str, 'h');
	one(str, 'l');
	one(str, 'o');
	one(str, 'd');
	one(str, 'z');
	one(str, '\0');
	one(str, 'l' + 256);
	one(str, -'l');
	one("", 'a');
	one("", '\0');
	one("a", 'a');
	one("aaaa", 'a');
	one("abcabc", 'a');
	one("abcabc", 'c');
	one("/a/b/c", '/');
	one("\xff\x80\xff", 255);
	one("\xff\x80\xff", -1);
	one("\xff\x80\xff", 128);
	c = -1;
	while (c <= 255)
		one(str, c++);
	return (done("ft_strrchr"));
}
