#include "check.h"
#include <ctype.h>

int	main(void)
{
	int	c;

	c = -1;
	while (c <= 255)
	{
		if (!!ft_isalpha(c) != !!isalpha(c))
			FAIL("ft_isalpha(%d) disagrees with libc", c);
		c++;
	}
	return (done("ft_isalpha"));
}
