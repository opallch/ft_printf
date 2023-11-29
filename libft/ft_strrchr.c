/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:11:08 by oleung            #+#    #+#             */
/*   Updated: 2023/11/23 16:42:55 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occ;
	int		i;

	last_occ = NULL;
	i = 0;
	c %= 256;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_occ = ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		last_occ = ((char *)s + i);
	return (last_occ);
}
