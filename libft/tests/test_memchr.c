#include "check.h"

static void	one(const void *s, int c, size_t n)
{
	const void	*got;
	const void	*want;

	got = ft_memchr(s, c, n);
	want = memchr(s, c, n);
	if (got != want)
		FAIL("ft_memchr(%p, %d, %zu) = %p, expected %p", s, c, n, got, want);
}

int	main(void)
{
	char			str[] = "hello world";
	unsigned char	bin[] = {0, 1, 2, 255, 128, 0, 42};
	int				ints[] = {0x01020304, 0x05060708};

	one(str, 'h', 11);
	one(str, 'o', 11);
	one(str, 'd', 11);
	one(str, 'z', 11);
	one(str, '\0', 12);
	one(str, '\0', 11);
	one(str, 'o', 4);
	one(str, 'o', 5);
	one(str, 'h', 0);
	one(str, 'd', 10);
	one(str, 'o' + 256, 11);
	one(bin, 0, 7);
	one(bin, 255, 7);
	one(bin, 128, 7);
	one(bin, -1, 7);
	one(bin, 42, 7);
	one(bin + 1, 0, 6);
	one(ints, 0x04, sizeof(ints));
	one(ints, 0x08, sizeof(ints));
	one(ints, 0x05, sizeof(ints));
	return (done("ft_memchr"));
}
