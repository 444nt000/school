#include "check.h"

static void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 'a' + 'A';
}

static void	replace_with_index(unsigned int i, char *c)
{
	*c = '0' + (i % 10);
}

static void	one(char *s, void (*f)(unsigned int, char *), const char *want)
{
	ft_striteri(s, f);
	CHECK_STR(s, want);
}

int	main(void)
{
	char	buf1[] = "hello world";
	char	buf2[] = "abcdefghijk";
	char	buf3[] = "";
	char	buf4[] = "a";
	char	buf5[] = "ALREADY UPPER";

	one(buf1, to_upper, "HELLO WORLD");
	one(buf2, replace_with_index, "01234567890");
	one(buf3, to_upper, "");
	one(buf4, to_upper, "A");
	one(buf5, to_upper, "ALREADY UPPER");
	ft_striteri(NULL, to_upper);
	ft_striteri(buf1, NULL);
	CHECK_STR(buf1, "HELLO WORLD");
	return (done("ft_striteri"));
}
