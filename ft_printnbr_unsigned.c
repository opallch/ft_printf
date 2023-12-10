/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:55:05 by oleung            #+#    #+#             */
/*   Updated: 2023/12/10 10:03:51 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int get_n_digits_unsigned(unsigned int n, int base)
{
    int n_digits;
    
    n_digits = 0;
    if (n == 0)
        n_digits++;
    while(n > 0)
    {
        n_digits++;
        n /= base;
    }
    return (n_digits);
}

static void	ft_putnbr_base_fd_unsigned(unsigned int n, char *base, int fd)
{   
    if (fd != -1)
	{
		if (n < (unsigned int) ft_strlen(base))
        {
            write(fd, &base[n], sizeof(char));
        }
        else
		{   
			ft_putnbr_base_fd_unsigned(n / (unsigned int) ft_strlen(base), base, fd);
			ft_putnbr_base_fd_unsigned(n % (unsigned int) ft_strlen(base), base, fd);
		}
	}
}

int ft_printnbr_unsigned(unsigned int n, char *base)
{
    if (ft_strlen(base) == 10)
        ft_putnbr_base_fd_unsigned(n, base, 1);
    if (ft_strlen(base) == 16)
        ft_putnbr_base_fd_unsigned(n, base, 1);
    return (get_n_digits_unsigned(n, ft_strlen(base)));
}