#include "check.h"

#define BUF 16

static void	one(const void *src, size_t n)
{
	unsigned char	got[BUF];
	unsigned char	want[BUF];
	void			*ret;

	memset(got, '#', BUF);
	memset(want, '#', BUF);
	ret = ft_memcpy(got, src, n);
	memcpy(want, src, n);
	if (ret != got)
		FAIL("ft_memcpy(dst, src, %zu) returned %p, expected dst", n, ret);
	if (memcmp(got, want, BUF) != 0)
		FAIL("ft_memcpy(dst, src, %zu) wrote a wrong buffer", n);
}

int	main(void)
{
	unsigned char	bin[] = {0, 1, 2, 255, 128, 0, 42, 7};
	int				ints[] = {0x01020304, 0x05060708};
	int				dst_ints[2];

	one("hello", 0);
	one("hello", 1);
	one("hello", 5);
	one("hello", 6);
	one("hello world", 11);
	one("hello world", 12);
	one("", 1);
	one(bin, 8);
	one(bin, 4);
	one(bin + 1, 7);
	ft_memcpy(dst_ints, ints, sizeof(ints));
	CHECK(memcmp(dst_ints, ints, sizeof(ints)) == 0);
	CHECK(ft_memcpy(NULL, NULL, 0) == NULL);
	return (done("ft_memcpy"));
}
