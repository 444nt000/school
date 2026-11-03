#include "check.h"
#include <ctype.h>

int	main(void)
{
	int	c;

	c = -1;
	while (c <= 255)
	{
		if (!!ft_isalnum(c) != !!isalnum(c))
			FAIL("ft_isalnum(%d) disagrees with libc", c);
		c++;
	}
	return (done("ft_isalnum"));
}
