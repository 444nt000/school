#include "check.h"
#include <ctype.h>

int	main(void)
{
	int	c;

	c = -1;
	while (c <= 255)
	{
		if (!!ft_isprint(c) != !!isprint(c))
			FAIL("ft_isprint(%d) disagrees with libc", c);
		c++;
	}
	CHECK(ft_isprint(' '));
	CHECK(!ft_isprint(127));
	return (done("ft_isprint"));
}
