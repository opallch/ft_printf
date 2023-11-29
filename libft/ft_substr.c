/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:53:29 by oleung            #+#    #+#             */
/*   Updated: 2023/11/23 21:20:54 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* returns "" if start >= ft_strlen(s)*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (start >= ft_strlen(s))
		substr = malloc(1 * sizeof(char));
	else if (ft_strlen(s) > len)
		substr = malloc((len + 1) * sizeof(char));
	else if (ft_strlen(s) > (len - start))
		substr = malloc((len - start + 1) * sizeof(char));
	else
		substr = malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	if (!substr || !s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substr[i] = 0;
		return (substr);
	}
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = 0;
	return (substr);
}
