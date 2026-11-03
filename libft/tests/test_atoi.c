#include "check.h"

int	main(void)
{
	static const char	*cases[] = {"0", "-0", "+0", "42", "-42", "+42", " -1 ",
			"   \t\n\v\f\r123", "\n\n+\t-2147483648 -", "\n\t\v\f\r2147483647x",
			"2147483647", "-2147483648", "0042", "-0042", "12abc34", "abc", "",
			" ", "-", "+", "--5", "++5", "+-5", "-+5", "5-3", " 7garbage", ".5",
			"1 2 3", NULL};
	int					i;

	i = 0;
	while (cases[i])
	{
		if (ft_atoi(cases[i]) != atoi(cases[i]))
			FAIL("ft_atoi(\"%s\") = %d, expected %d", cases[i],
				ft_atoi(cases[i]), atoi(cases[i]));
		i++;
	}
	return (done("ft_atoi"));
}
