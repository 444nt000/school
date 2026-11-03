#include "check.h"

static char	identity(unsigned int i, char c)
{
	(void)i;
	return (c);
}

static char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}

static char	index_as_digit(unsigned int i, char c)
{
	(void)c;
	return ('0' + (i % 10));
}

static void	one(const char *s, char (*f)(unsigned int, char), const char *want)
{
	char	*got;

	got = ft_strmapi(s, f);
	CHECK_STR(got, want);
	free(got);
}

int	main(void)
{
	one("hello", identity, "hello");
	one("hello", to_upper, "HELLO");
	one("Hello World", to_upper, "HELLO WORLD");
	one("", identity, "");
	one("abcdefghijk", index_as_digit, "01234567890");
	one("a", index_as_digit, "0");
	CHECK(ft_strmapi(NULL, identity) == NULL);
	CHECK(ft_strmapi("abc", NULL) == NULL);
	return (done("ft_strmapi"));
}
