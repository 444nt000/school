#include "check.h"

static void	one(const char *s1, const char *s2, const char *want)
{
	char	*got;

	got = ft_strjoin(s1, s2);
	CHECK_STR(got, want);
	free(got);
}

int	main(void)
{
	char	*got;

	one("hello", " world", "hello world");
	one("a", "b", "ab");
	one("abc", "d", "abcd");
	one("a", "bcd", "abcd");
	one("", "abc", "abc");
	one("abc", "", "abc");
	one("", "", "");
	one("42", "42", "4242");
	one("same", "same", "samesame");
	one("with space ", " and more", "with space  and more");
	one("long string number one, ", "long string number two",
		"long string number one, long string number two");
	got = ft_strjoin(NULL, "abc");
	CHECK(got == NULL);
	got = ft_strjoin("abc", NULL);
	CHECK(got == NULL);
	return (done("ft_strjoin"));
}
