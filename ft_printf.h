/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:07:52 by oleung            #+#    #+#             */
/*   Updated: 2023/12/10 10:59:04 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
void	ft_putnbr_base_fd(int n, char *base, int fd);
int		ft_printnbr(int n, char *base);
int		ft_printnbr_unsigned(unsigned int n, char *base);
void	ft_putptr_fd(long long unsigned int ptr, int fd);
int		ft_printptr(long long unsigned int ptr);

#endif