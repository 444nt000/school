#include "check.h"

static int	g_del_calls;
static void	*g_last_content;

static void	del(void *content)
{
	g_del_calls++;
	g_last_content = content;
}

int	main(void)
{
	t_list	*node;

	g_del_calls = 0;
	node = ft_lstnew((void *)42);
	ft_lstdelone(node, del);
	CHECK_INT(g_del_calls, 1);
	CHECK(g_last_content == (void *)42);
	ft_lstdelone(NULL, del);
	CHECK_INT(g_del_calls, 1);
	node = ft_lstnew((void *)1);
	ft_lstdelone(node, NULL);
	free(node);
	return (done("ft_lstdelone"));
}
