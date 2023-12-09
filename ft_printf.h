/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:07:52 by oleung            #+#    #+#             */
/*   Updated: 2023/12/09 12:14:55 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "./libft/libft.h"

int ft_printf(const char *format, ...);
void	ft_putnbr_base_fd(int n, char *base, int fd);
void    ft_putptr_fd(long long unsigned int ptr, int fd);
int ft_printchar(char c);
int ft_printstr(char *str);
int ft_printnbr(int n, char *base);
int get_n_digits(int n, int base);

# endif