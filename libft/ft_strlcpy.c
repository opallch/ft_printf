/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:51:02 by oleung            #+#    #+#             */
/*   Updated: 2023/11/13 16:39:48 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The	strlcpy(void) function copies up to size - 1 characters
from the NUL-terminated string src to dst,
NUL-terminating the result.

guarantee to NUL-terminate the result (as long as size is larger than 0

Note that a byte for the NUL should be included in size.

return the total length of the string they tried to create.
For	strlcpy(void) that means the length of src.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	pos;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	pos = 0;
	while (src[pos] && pos < size - 1)
	{
		dest[pos] = src[pos];
		pos++;
	}
	dest[pos] = '\0';
	return (ft_strlen(src));
}
