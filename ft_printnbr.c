/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:00:01 by oleung            #+#    #+#             */
/*   Updated: 2023/12/10 09:04:37 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_n_digits(long long n, int base)
{
	int	n_digits;

	n_digits = 0;
	if (n == -2147483648)
		n_digits = 11;
	else if (n <= 0)
	{
		n *= -1;
		n_digits++;
	}
	while (n > 0)
	{
		n_digits++;
		n /= base;
	}
	return (n_digits);
}

void	ft_putnbr_base_fd(int n, char *base, int fd)
{
	if (fd != -1)
	{
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11 * sizeof(char));
			return ;
		}
		if (n < 0)
		{
			write(fd, "-", sizeof(char));
			n *= -1;
		}
		if (n < (int)ft_strlen(base))
		{
			write(fd, &base[n], sizeof(char));
		}
		else
		{
			ft_putnbr_base_fd(n / (int)ft_strlen(base), base, fd);
			ft_putnbr_base_fd(n % (int)ft_strlen(base), base, fd);
		}
	}
}

int	ft_printnbr(int n, char *base)
{
	if (ft_strlen(base) == 10)
		ft_putnbr_fd(n, 1);
	if (ft_strlen(base) == 16)
		ft_putnbr_base_fd(n, base, 1);
	return (get_n_digits(n, ft_strlen(base)));
}
