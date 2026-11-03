#include "check.h"

static void	one(int n, const char *want)
{
	char	*got;

	got = ft_itoa(n);
	CHECK_STR(got, want);
	free(got);
}

int	main(void)
{
	one(0, "0");
	one(1, "1");
	one(-1, "-1");
	one(9, "9");
	one(10, "10");
	one(-10, "-10");
	one(99, "99");
	one(100, "100");
	one(-100, "-100");
	one(42, "42");
	one(-42, "-42");
	one(1000000, "1000000");
	one(-999, "-999");
	one(2147483647, "2147483647");
	one(-2147483648, "-2147483648");
	return (done("ft_itoa"));
}
