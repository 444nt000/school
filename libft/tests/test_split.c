#include "check.h"

static void	one(const char *s, char c, const char **want)
{
	char	**got;
	int		i;

	got = ft_split(s, c);
	if (!got)
	{
		FAIL("ft_split(\"%s\", '%c') returned NULL", s, c);
		return ;
	}
	i = 0;
	while (want[i])
	{
		if (!got[i])
		{
			FAIL("ft_split(\"%s\", '%c'): missing word %d", s, c, i);
			break ;
		}
		CHECK_STR(got[i], want[i]);
		i++;
	}
	if (!want[i] && got[i])
		FAIL("ft_split(\"%s\", '%c'): too many words", s, c);
	i = 0;
	while (got[i])
		free(got[i++]);
	free(got);
}

int	main(void)
{
	one("hello world foo", ' ', (const char *[]){"hello", "world", "foo",
		NULL});
	one("   abc   def   ", ' ', (const char *[]){"abc", "def", NULL});
	one("      ", ' ', (const char *[]){NULL});
	one("", ' ', (const char *[]){NULL});
	one("oneword", ' ', (const char *[]){"oneword", NULL});
	one("a", ' ', (const char *[]){"a", NULL});
	one("a b c", ',', (const char *[]){"a b c", NULL});
	one("abc", '\0', (const char *[]){"abc", NULL});
	one(",a,,b,,,c,", ',', (const char *[]){"a", "b", "c", NULL});
	one("aaa", 'a', (const char *[]){NULL});
	CHECK(ft_split(NULL, ' ') == NULL);
	return (done("ft_split"));
}
