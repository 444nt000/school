#include "check.h"

int	main(void)
{
	char	*dup;
	char	s[] = "hello";
	char	big[4096];
	int		i;

	dup = ft_strdup("hello world");
	CHECK_STR(dup, "hello world");
	free(dup);
	dup = ft_strdup("");
	CHECK(dup != NULL);
	CHECK_STR(dup, "");
	free(dup);
	dup = ft_strdup(s);
	CHECK(dup != (char *)s);
	free(dup);
	dup = ft_strdup(s);
	dup[0] = 'H';
	CHECK_INT(s[0], 'h');
	free(dup);
	i = 0;
	while (i < 4095)
	{
		big[i] = 'a' + (i % 26);
		i++;
	}
	big[4095] = '\0';
	dup = ft_strdup(big);
	CHECK_STR(dup, big);
	free(dup);
	dup = ft_strdup("abc");
	CHECK_INT(strlen(dup), 3);
	free(dup);
	return (done("ft_strdup"));
}
