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
	ft_putendl_fd(s, fds[1]);
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
	one("hello", "hello\n");
	one("", "\n");
	one("a", "a\n");
	one("line\nwith\nnewlines", "line\nwith\nnewlines\n");
	/*
	** NULL s: ft_putstr_fd no-ops but ft_putendl_fd still unconditionally
	** writes the trailing '\n' (mirrors ft_putstr_fd + ft_putchar_fd with
	** no NULL-skip of its own, matching the subject's behavior).
	*/
	one(NULL, "\n");
	ft_putendl_fd("ignored", -1);
	ft_putendl_fd("ignored", 999);
	return (done("ft_putendl_fd"));
}
