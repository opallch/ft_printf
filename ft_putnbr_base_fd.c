/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:21:57 by oleung            #+#    #+#             */
/*   Updated: 2023/12/07 14:58:18 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		if (n < (int) ft_strlen(base))
        {
            write(fd, &base[n], sizeof(char));
        }
        else
		{   
			ft_putnbr_base_fd(n / (int) ft_strlen(base), base, fd);
			ft_putnbr_base_fd(n % (int) ft_strlen(base), base, fd);
		}
	}
}