#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		ft_strlen(NULL);
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
