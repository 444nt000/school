#include "check.h"

#define BUF 20

static void	one_copy(const char *init, size_t dst_off, size_t src_off, size_t n)
{
	char	buf1[BUF];
	char	buf2[BUF];

	memset(buf1, '#', BUF);
	memset(buf2, '#', BUF);
	memcpy(buf1, init, strlen(init) + 1);
	memcpy(buf2, init, strlen(init) + 1);
	ft_memmove(buf1 + dst_off, buf1 + src_off, n);
	memmove(buf2 + dst_off, buf2 + src_off, n);
	if (memcmp(buf1, buf2, BUF) != 0)
		FAIL("ft_memmove overlap dst+%zu src+%zu n=%zu mismatch", dst_off,
			src_off, n);
}

int	main(void)
{
	void	*ret;
	char	buf[10] = "abcdefghi";
	char	big1[256];
	char	big2[256];
	int		i;

	one_copy("0123456789abcdefghi", 0, 0, 12);
	one_copy("0123456789abcdefghi", 3, 0, 10);
	one_copy("0123456789abcdefghi", 0, 3, 10);
	one_copy("0123456789abcdefghi", 0, 0, 19);
	one_copy("abcdefghi", 2, 0, 0);
	one_copy("abcde", 1, 0, 1);
	ret = ft_memmove(buf, buf + 1, 5);
	CHECK(ret == buf);
	i = 0;
	while (i < 256)
	{
		big1[i] = (char)i;
		big2[i] = (char)i;
		i++;
	}
	ft_memmove(big1 + 50, big1 + 10, 150);
	memmove(big2 + 50, big2 + 10, 150);
	CHECK(memcmp(big1, big2, 256) == 0);
	return (done("ft_memmove"));
}
