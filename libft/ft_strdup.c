/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:30:15 by oleung            #+#    #+#             */
/*   Updated: 2023/11/15 23:49:51 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*result;

	i = 0;
	result = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (result)
	{
		while (src[i])
		{
			result[i] = src[i];
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
