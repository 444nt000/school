#include "check.h"

#define BUF 16

static void	one(int c, size_t n)
{
	unsigned char	got[BUF];
	unsigned char	want[BUF];
	void			*ret;

	memset(got, '#', BUF);
	memset(want, '#', BUF);
	ret = ft_memset(got, c, n);
	memset(want, c, n);
	if (ret != got)
		FAIL("ft_memset(dst, %d, %zu) returned %p, expected dst", c, n, ret);
	if (memcmp(got, want, BUF) != 0)
		FAIL("ft_memset(dst, %d, %zu) wrote a wrong buffer", c, n);
}

int	main(void)
{
	int	ints[4];
	int	want_ints[4];

	one('a', 0);
	one('a', 1);
	one('a', 5);
	one('a', BUF);
	one(0, 8);
	one(0, BUF);
	one(255, 8);
	one(-1, 8);
	one(128, 8);
	one('a' + 256, 8);
	one(256, 8);
	one(-256, 8);
	memset(ints, 1, sizeof(ints));
	memset(want_ints, 1, sizeof(want_ints));
	ft_memset(ints, 0, sizeof(ints));
	memset(want_ints, 0, sizeof(want_ints));
	CHECK(memcmp(ints, want_ints, sizeof(ints)) == 0);
	CHECK(ft_memset(NULL, 'a', 0) == NULL);
	return (done("ft_memset"));
}
