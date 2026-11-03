#include "check.h"

static void	incr(void *content)
{
	int	*p;

	p = (int *)content;
	(*p)++;
}

int	main(void)
{
	t_list	*lst;
	int		values[3];

	values[0] = 0;
	values[1] = 10;
	values[2] = 20;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(&values[0]));
	ft_lstadd_back(&lst, ft_lstnew(&values[1]));
	ft_lstadd_back(&lst, ft_lstnew(&values[2]));
	ft_lstiter(lst, incr);
	CHECK_INT(values[0], 1);
	CHECK_INT(values[1], 11);
	CHECK_INT(values[2], 21);
	ft_lstiter(NULL, incr);
	ft_lstiter(lst, NULL);
	free(lst->next->next);
	free(lst->next);
	free(lst);
	return (done("ft_lstiter"));
}
