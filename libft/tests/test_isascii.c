#include "check.h"
#include <ctype.h>

int	main(void)
{
	int	c;

	c = -1;
	while (c <= 255)
	{
		if (!!ft_isascii(c) != !!isascii(c))
			FAIL("ft_isascii(%d) disagrees with libc", c);
		c++;
	}
	CHECK(ft_isascii(127));
	CHECK(!ft_isascii(128));
	CHECK(!ft_isascii(256));
	CHECK(!ft_isascii(-1));
	return (done("ft_isascii"));
}
