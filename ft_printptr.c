/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:05:07 by oleung            #+#    #+#             */
/*   Updated: 2023/12/10 10:54:08 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_n_digits_llu(long long unsigned int n, int base)
{
	int	n_digits;

	n_digits = 0;
	while (n > 0)
	{
		n_digits++;
		n /= base;
	}
	return (n_digits);
}

static void	ft_putnbr_base_llu_fd(long long unsigned int n, char *base, int fd)
{
	if (fd != -1)
	{
		if (n < ft_strlen(base))
		{
			write(fd, &base[n], sizeof(char));
		}
		else
		{
			ft_putnbr_base_llu_fd(n / ft_strlen(base), base, fd);
			ft_putnbr_base_llu_fd(n % ft_strlen(base), base, fd);
		}
	}
}

static int	ft_printnbr_base_llu(long long unsigned int n, char *base)
{
	ft_putnbr_base_llu_fd(n, base, 1);
	return (get_n_digits_llu(n, ft_strlen(base)));
}

int	ft_printptr(long long unsigned int ptr)
{
	int	n_char;

	n_char = 0;
	if (!ptr)
		n_char = write(1, "(nil)", 5);
	else
	{
		n_char += write(1, "0x", 2);
		n_char += ft_printnbr_base_llu(ptr, "0123456789abcdef");
	}
	return (n_char);
}
