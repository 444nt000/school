#include "check.h"

int	main(void)
{
	t_list	*node;
	int		value;

	value = 42;
	node = ft_lstnew(&value);
	CHECK(node != NULL);
	CHECK(node->content == &value);
	CHECK(node->next == NULL);
	free(node);
	node = ft_lstnew(NULL);
	CHECK(node != NULL);
	CHECK(node->content == NULL);
	CHECK(node->next == NULL);
	free(node);
	return (done("ft_lstnew"));
}
