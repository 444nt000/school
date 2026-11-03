#include "check.h"

static void	one(const char *s, int c)
{
	const char	*got;
	const char	*want;

	got = ft_strchr(s, c);
	want = strchr(s, c);
	if (got != want)
		FAIL("ft_strchr(\"%s\", %d) = %p, expected %p", s, c, got, want);
}

int	main(void)
{
	char	s[] = "hello world";

	one(s, 'w');
	one(s, 'a');
	one(s, 'z');
	one(s, 'h');
	one(s, 'o');
	one(s, '\0');
	one("", 'a');
	one("", '\0');
	one(s, -10);
	one(s, 'h' + 256);
	return (done("ft_strchr"));
}
