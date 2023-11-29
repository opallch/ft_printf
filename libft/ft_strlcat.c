/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:00 by oleung            #+#    #+#             */
/*   Updated: 2023/11/19 21:11:18 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	pos_dest;
	size_t	pos_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen((char *)src);
	pos_dest = len_dest;
	pos_src = 0;
	while (src[pos_src] && pos_dest < size)
		dest[pos_dest++] = src[pos_src++];
	if ((len_dest + pos_src) == size && len_dest < size)
		pos_dest--;
	dest[pos_dest] = '\0';
	if (size > len_dest)
		return (len_src + len_dest);
	else
		return (len_src + size);
}
