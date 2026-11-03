#include "check.h"

#define BUF 16

static size_t	ref(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	n;

	len = strlen(src);
	if (size == 0)
		return (len);
	n = len;
	if (n > size - 1)
		n = size - 1;
	memcpy(dst, src, n);
	dst[n] = '\0';
	return (len);
}

static void	one(const char *src, size_t size)
{
	char	got[BUF];
	char	want[BUF];
	size_t	r_got;
	size_t	r_want;

	memset(got, '#', BUF);
	memset(want, '#', BUF);
	r_got = ft_strlcpy(got, src, size);
	r_want = ref(want, src, size);
	if (r_got != r_want)
		FAIL("ft_strlcpy(\"%s\", %zu) returned %zu, expected %zu", src, size,
			r_got, r_want);
	if (memcmp(got, want, BUF) != 0)
		FAIL("ft_strlcpy(\"%s\", %zu) wrote a wrong buffer", src, size);
}

static void	dst_untouched_when_size_zero(void)
{
	char	got[BUF];
	size_t	r;

	memset(got, '#', BUF);
	r = ft_strlcpy(got, "hello", 0);
	if (r != 5)
		FAIL("ft_strlcpy(dst, \"hello\", 0) returned %zu, expected 5", r);
	if (memcmp(got, "################", BUF) != 0)
		FAIL("ft_strlcpy(dst, \"hello\", 0) wrote into dst");
}

int	main(void)
{
	one("hello", 0);
	one("hello", 1);
	one("hello", 2);
	one("hello", 5);
	one("hello", 6);
	one("hello", 7);
	one("hello", BUF);
	one("hello world", 5);
	one("hello world", 12);
	one("", 0);
	one("", 1);
	one("", 5);
	one("a", 1);
	one("a", 2);
	one("a", 3);
	one("abc\0def", 7);
	dst_untouched_when_size_zero();
	return (done("ft_strlcpy"));
}
