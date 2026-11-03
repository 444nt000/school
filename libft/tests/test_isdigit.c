#include "check.h"
#include <ctype.h>

int	main(void)
{
	int	c;

	c = -1;
	while (c <= 255)
	{
		if (!!ft_isdigit(c) != !!isdigit(c))
			FAIL("ft_isdigit(%d) disagrees with libc", c);
		c++;
	}
	return (done("ft_isdigit"));
}
