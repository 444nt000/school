#include "check.h"

static void	one(char c, const char *want_byte)
{
	int		fds[2];
	char	buf[2];
	ssize_t	n;

	if (pipe(fds) == -1)
	{
		FAIL("pipe() failed");
		return ;
	}
	ft_putchar_fd(c, fds[1]);
	close(fds[1]);
	n = read(fds[0], buf, 1);
	close(fds[0]);
	if (n != 1 || buf[0] != want_byte[0])
		FAIL("ft_putchar_fd('%c') wrote wrong byte", c);
}

int	main(void)
{
	one('a', "a");
	one('Z', "Z");
	one('\n', "\n");
	one('0', "0");
	one(' ', " ");
	one('\0', "\0");
	ft_putchar_fd('x', -1);
	ft_putchar_fd('x', 999);
	return (done("ft_putchar_fd"));
}
