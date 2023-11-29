/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:42:43 by oleung            #+#    #+#             */
/*   Updated: 2023/11/21 00:46:22 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int base, int exp)
{
	int	result;

	result = base;
	if (exp == 0)
		return (1);
	while (exp > 1)
	{
		result *= base;
		exp--;
	}
	return (result);
}

static int	get_exp(int nb)
{
	int	exp;

	exp = 0;
	while (nb / 10 != 0)
	{
		nb /= 10;
		exp++;
	}
	return (exp);
}

static void	ft_itoa_aux(long int n, char *result, int exp)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		result[i++] = '-';
		n *= -1;
	}
	while (exp >= 0)
	{
		result[i++] = '0' + n / power(10, exp);
		n %= power(10, exp);
		exp--;
	}
	result[i] = 0;
}

char	*ft_itoa(int n)
{
	char	*result;
	int		exp;

	exp = get_exp(n);
	if (n < 0)
		result = malloc((exp + 3) * sizeof(char));
	else
		result = malloc((exp + 2) * sizeof(char));
	if (!result)
		return (NULL);
	ft_itoa_aux((long int)n, result, exp);
	return (result);
}
