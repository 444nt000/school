#include "check.h"

static int	g_del_calls;

static void	del(void *content)
{
	(void)content;
	g_del_calls++;
}

int	main(void)
{
	t_list	*lst;

	g_del_calls = 0;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew((void *)1));
	ft_lstadd_back(&lst, ft_lstnew((void *)2));
	ft_lstadd_back(&lst, ft_lstnew((void *)3));
	ft_lstclear(&lst, del);
	CHECK_INT(g_del_calls, 3);
	CHECK(lst == NULL);
	ft_lstclear(&lst, del);
	CHECK_INT(g_del_calls, 3);
	ft_lstclear(NULL, del);
	lst = ft_lstnew((void *)1);
	ft_lstclear(&lst, NULL);
	free(lst);
	return (done("ft_lstclear"));
}
