#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// **lst is the first link in a list
// *new is element to be added
// add element new at beginning of list
