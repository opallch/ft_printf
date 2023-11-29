/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:18:18 by oleung            #+#    #+#             */
/*   Updated: 2023/11/22 01:58:45 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*tmp;

	if (lst)
	{
		next = *lst;
		while (next)
		{
			del(next->content);
			tmp = next;
			next = next->next;
			free(tmp);
		}
		*lst = NULL;
	}
}
