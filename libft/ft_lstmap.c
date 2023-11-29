/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:36:59 by oleung            #+#    #+#             */
/*   Updated: 2023/11/22 01:58:58 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*next;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (NULL);
	next = new_list;
	lst = lst->next;
	while (lst)
	{
		next->next = ft_lstnew(f(lst->content));
		if (next->next)
		{
			lst = lst->next;
			next = next->next;
		}
		else
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
	}
	return (new_list);
}
