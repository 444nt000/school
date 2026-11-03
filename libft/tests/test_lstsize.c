#include "check.h"

int	main(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	CHECK_INT(ft_lstsize(NULL), 0);
	lst = NULL;
	a = ft_lstnew((void *)1);
	ft_lstadd_front(&lst, a);
	CHECK_INT(ft_lstsize(lst), 1);
	b = ft_lstnew((void *)2);
	ft_lstadd_front(&lst, b);
	c = ft_lstnew((void *)3);
	ft_lstadd_front(&lst, c);
	CHECK_INT(ft_lstsize(lst), 3);
	free(a);
	free(b);
	free(c);
	return (done("ft_lstsize"));
}
