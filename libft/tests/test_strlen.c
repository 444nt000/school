#include "check.h"

int	main(void)
{
	CHECK_INT(ft_strlen(""), 0);
	CHECK_INT(ft_strlen("a"), 1);
	CHECK_INT(ft_strlen("hello"), 5);
	CHECK_INT(ft_strlen("hello world"), 11);
	CHECK_INT(ft_strlen("\t\n\v"), 3);
	CHECK_INT(ft_strlen("abc\0def"), 3);
	return (done("ft_strlen"));
}
