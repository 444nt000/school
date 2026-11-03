#include "check.h"

static void	*dup_int(void *content)
{
	int	*new;

	new = malloc(sizeof(int));
	if (!new)
		return (NULL);
	*new = *(int *)content * 2;
	return (new);
}

static void	*to_null(void *content)
{
	(void)content;
	return (NULL);
}

static void	free_del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*mapped;
	int		values[3];

	values[0] = 1;
	values[1] = 2;
	values[2] = 3;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(&values[0]));
	ft_lstadd_back(&lst, ft_lstnew(&values[1]));
	ft_lstadd_back(&lst, ft_lstnew(&values[2]));
	mapped = ft_lstmap(lst, dup_int, free_del);
	CHECK(mapped != NULL);
	CHECK_INT(ft_lstsize(mapped), 3);
	CHECK_INT(*(int *)mapped->content, 2);
	CHECK_INT(*(int *)mapped->next->content, 4);
	CHECK_INT(*(int *)mapped->next->next->content, 6);
	ft_lstclear(&mapped, free_del);
	CHECK(ft_lstmap(NULL, dup_int, free_del) == NULL);
	CHECK(ft_lstmap(lst, NULL, free_del) == NULL);
	CHECK(ft_lstmap(lst, dup_int, NULL) == NULL);
	mapped = ft_lstmap(lst, to_null, free_del);
	CHECK(mapped != NULL);
	CHECK_INT(ft_lstsize(mapped), 3);
	CHECK(mapped->content == NULL);
	ft_lstclear(&mapped, free_del);
	free(lst->next->next);
	free(lst->next);
	free(lst);
	return (done("ft_lstmap"));
}
