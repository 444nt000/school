#include "check.h"
#include <stdint.h>

static int	all_zero(const unsigned char *p, size_t n)
{
	while (n--)
		if (*p++)
			return (0);
	return (1);
}

static void	dirty_heap(size_t n)
{
	void	*p;

	p = malloc(n);
	if (p)
		memset(p, 0xAA, n);
	free(p);
}

static void	one(size_t nmemb, size_t size)
{
	unsigned char	*p;

	dirty_heap(nmemb * size);
	p = ft_calloc(nmemb, size);
	if (!p)
		FAIL("ft_calloc(%zu, %zu) returned NULL", nmemb, size);
	else if (!all_zero(p, nmemb * size))
		FAIL("ft_calloc(%zu, %zu) memory is not zeroed", nmemb, size);
	else
		memset(p, 0xFF, nmemb * size);
	free(p);
}

static void	zero(size_t nmemb, size_t size)
{
	void	*p;

	p = ft_calloc(nmemb, size);
	free(p);
}

static void	overflow(size_t nmemb, size_t size)
{
	void	*p;

	p = ft_calloc(nmemb, size);
	if (p)
		FAIL("ft_calloc(%zu, %zu) should fail on overflow", nmemb, size);
	free(p);
}

int	main(void)
{
	one(1, 1);
	one(1, 8);
	one(8, 1);
	one(5, sizeof(int));
	one(4, sizeof(char *));
	one(100, 1);
	one(1, 100);
	one(10, 10);
	one(1000, sizeof(int));
	one(3, 1000);
	zero(0, 0);
	zero(0, 5);
	zero(5, 0);
	overflow(SIZE_MAX, 2);
	overflow(2, SIZE_MAX);
	overflow(SIZE_MAX / 2 + 1, 2);
	overflow(2, SIZE_MAX / 2 + 1);
	overflow(SIZE_MAX, SIZE_MAX);
	return (done("ft_calloc"));
}
