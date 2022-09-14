/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:49:21 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:22 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*element;

	newlist = NULL;
	if (lst == NULL)
		ft_strlen(NULL);
	while (lst)
	{
		element = ft_lstnew(f(lst->content));
		if (!element)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, element);
		lst = lst->next;
	}
	return (newlist);
}

// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
// {
// 	t_list	*newlist;
// 	t_list	*startnewlist;
// 	startnewlist = NULL;
// 	newlist = malloc(sizeof(t_list) * ft_lstsize(lst));
// 	if (!newlist)
// 	{
// 		ft_lstclear(&startnewlist, del);
// 		return (NULL);
// 	}
// 	while (lst)
// 	{
// 		newlist = lst;
// 		newlist->content = f(newlist->content);
// 		lst = lst->next;
// 		newlist = newlist->next;
// 	}
// 	return (startnewlist);
// }
