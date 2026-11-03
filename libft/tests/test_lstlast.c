#include "check.h"

int	main(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;

	CHECK(ft_lstlast(NULL) == NULL);
	lst = ft_lstnew((void *)1);
	CHECK(ft_lstlast(lst) == lst);
	a = ft_lstnew((void *)2);
	lst->next = a;
	CHECK(ft_lstlast(lst) == a);
	b = ft_lstnew((void *)3);
	a->next = b;
	CHECK(ft_lstlast(lst) == b);
	free(lst);
	free(a);
	free(b);
	return (done("ft_lstlast"));
}
