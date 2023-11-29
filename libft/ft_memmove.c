/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:05:49 by oleung            #+#    #+#             */
/*   Updated: 2023/11/23 20:10:04 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_cpy;
	const char	*src_cpy;

	if (!dest && !src)
		return (NULL);
	dest_cpy = (char *)dest;
	src_cpy = (char *)src;
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			dest_cpy[n] = src_cpy[n];
	}
	return (dest);
}
