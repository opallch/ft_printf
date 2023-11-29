/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:07:45 by oleung            #+#    #+#             */
/*   Updated: 2023/11/21 00:51:02 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

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
		if (n < 10)
		{
			c = '0' + n;
			write(fd, &c, sizeof(char));
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
