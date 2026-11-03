#include "check.h"
#include <ctype.h>

int	main(void)
{
	int	c;

	c = -1;
	while (c <= 255)
	{
		if (ft_tolower(c) != tolower(c))
			FAIL("ft_tolower(%d) = %d, expected %d", c, ft_tolower(c),
				tolower(c));
		c++;
	}
	return (done("ft_tolower"));
}
