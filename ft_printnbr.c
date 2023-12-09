/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 12:00:01 by oleung            #+#    #+#             */
/*   Updated: 2023/12/09 12:34:45 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_n_digits(int n, int base)
{
    int n_digits;
    
    n_digits = 0;
    if (n == -2147483648)
        n_digits = 11;
    else if (n <= 0)
    {
        n *= -1;
        n_digits++;
    }
    while(n > 0)
    {
        n_digits++;
        n /= base;
    }
    return (n_digits);
}

int ft_printnbr(int n, char *base)
{
    if (ft_strlen(base) == 10)
        ft_putnbr_fd(n, 1);

    return (get_n_digits(n, ft_strlen(base)));
}