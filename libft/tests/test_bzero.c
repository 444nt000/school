#include "check.h"

#define BUF 16

static void	one(size_t offset, size_t n)
{
	unsigned char	got[BUF];
	unsigned char	want[BUF];

	memset(got, 'x', BUF);
	memset(want, 'x', BUF);
	ft_bzero(got + offset, n);
	memset(want + offset, 0, n);
	if (memcmp(got, want, BUF) != 0)
		FAIL("ft_bzero(buf + %zu, %zu) wrote a wrong buffer", offset, n);
}

int	main(void)
{
	int		ints[4];
	int		want_ints[4];
	char	str[] = "hello";

	one(0, 0);
	one(0, 1);
	one(0, 5);
	one(0, BUF);
	one(3, 4);
	one(BUF - 1, 1);
	one(BUF, 0);
	memset(ints, 1, sizeof(ints));
	memset(want_ints, 1, sizeof(want_ints));
	ft_bzero(ints, sizeof(ints));
	memset(want_ints, 0, sizeof(want_ints));
	CHECK(memcmp(ints, want_ints, sizeof(ints)) == 0);
	ft_bzero(str, 2);
	CHECK(str[0] == '\0' && str[1] == '\0' && str[2] == 'l');
	ft_bzero(NULL, 0);
	return (done("ft_bzero"));
}
