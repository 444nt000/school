#include "check.h"

int	main(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;
	t_list	*c;

	lst = NULL;
	a = ft_lstnew((void *)1);
	ft_lstadd_back(&lst, a);
	CHECK(lst == a);
	CHECK(lst->next == NULL);
	b = ft_lstnew((void *)2);
	ft_lstadd_back(&lst, b);
	CHECK(lst == a);
	CHECK(lst->next == b);
	CHECK(lst->next->next == NULL);
	c = ft_lstnew((void *)3);
	ft_lstadd_back(&lst, c);
	CHECK(ft_lstlast(lst) == c);
	CHECK_INT(ft_lstsize(lst), 3);
	ft_lstadd_back(NULL, a);
	ft_lstadd_back(&lst, NULL);
	CHECK_INT(ft_lstsize(lst), 3);
	free(a);
	free(b);
	free(c);
	return (done("ft_lstadd_back"));
}
