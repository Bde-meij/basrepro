/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:49:20 by bde-meij          #+#    #+#             */
/*   Updated: 2022/08/24 16:49:21 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlement;

	newlement = malloc(sizeof(t_list));
	if (!newlement)
		return (NULL);
	newlement->content = content;
	newlement->next = NULL;
	return (newlement);
}

// #include <stdio.h>
// int	main()
// {
// 	t_list *new;
// 	char *str = "hello";

// 	new = ft_lstnew(str);
// 	// printf("content of new: %s\n", new->content);
// 	t_list *new2;
// 	char *str2 = "world";
// 	new2 = ft_lstnew(str2);
// 	ft_lstadd_back(&new, new2);

// 	t_list *ptr;
// 	ptr = new;
// 	while (ptr)
// 	{
// 		printf("content of current node: %s\n", ptr->content);
// 		ptr = ptr->next;
// 	}
// }
