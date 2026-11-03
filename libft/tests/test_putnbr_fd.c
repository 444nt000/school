#include "check.h"

#define BUF 16

static void	one(int n, const char *want)
{
	int		fds[2];
	char	buf[BUF];
	ssize_t	r;

	if (pipe(fds) == -1)
	{
		FAIL("pipe() failed");
		return ;
	}
	ft_putnbr_fd(n, fds[1]);
	close(fds[1]);
	memset(buf, 0, BUF);
	r = read(fds[0], buf, BUF - 1);
	close(fds[0]);
	if (r < 0)
		r = 0;
	buf[r] = '\0';
	CHECK_STR(buf, want);
}

int	main(void)
{
	one(0, "0");
	one(1, "1");
	one(9, "9");
	one(-1, "-1");
	one(-9, "-9");
	one(10, "10");
	one(-10, "-10");
	one(42, "42");
	one(-42, "-42");
	one(100, "100");
	one(-100, "-100");
	one(123, "123");
	one(-123, "-123");
	one(1000000, "1000000");
	one(-999, "-999");
	one(2147483647, "2147483647");
	one(-2147483648, "-2147483648");
	ft_putnbr_fd(42, -1);
	ft_putnbr_fd(42, 999);
	return (done("ft_putnbr_fd"));
}
