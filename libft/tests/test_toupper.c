#include "check.h"
#include <ctype.h>

int	main(void)
{
	int	c;

	c = -1;
	while (c <= 255)
	{
		if (ft_toupper(c) != toupper(c))
			FAIL("ft_toupper(%d) = %d, expected %d", c, ft_toupper(c),
				toupper(c));
		c++;
	}
	return (done("ft_toupper"));
}
