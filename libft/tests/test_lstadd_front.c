#include "check.h"

int	main(void)
{
	t_list	*lst;
	t_list	*a;
	t_list	*b;

	lst = NULL;
	a = ft_lstnew((void *)1);
	ft_lstadd_front(&lst, a);
	CHECK(lst == a);
	CHECK(lst->next == NULL);
	b = ft_lstnew((void *)2);
	ft_lstadd_front(&lst, b);
	CHECK(lst == b);
	CHECK(lst->next == a);
	CHECK(lst->next->next == NULL);
	ft_lstadd_front(NULL, a);
	ft_lstadd_front(&lst, NULL);
	CHECK(lst == b);
	free(a);
	free(b);
	return (done("ft_lstadd_front"));
}
