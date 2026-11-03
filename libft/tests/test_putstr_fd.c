#include "check.h"

#define BUF 64

static void	one(char *s, const char *want)
{
	int		fds[2];
	char	buf[BUF];
	ssize_t	n;

	if (pipe(fds) == -1)
	{
		FAIL("pipe() failed");
		return ;
	}
	ft_putstr_fd(s, fds[1]);
	close(fds[1]);
	memset(buf, 0, BUF);
	n = read(fds[0], buf, BUF - 1);
	close(fds[0]);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	CHECK_STR(buf, want);
}

int	main(void)
{
	one("hello world", "hello world");
	one("", "");
	one("a", "a");
	one("line\nwith\nnewlines", "line\nwith\nnewlines");
	ft_putstr_fd(NULL, 1);
	ft_putstr_fd("ignored", -1);
	ft_putstr_fd("ignored", 999);
	return (done("ft_putstr_fd"));
}
