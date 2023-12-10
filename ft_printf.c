/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:42:05 by oleung            #+#    #+#             */
/*   Updated: 2023/12/10 10:57:41 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(va_list args, char format_specifier)
{
	int	n_char;

	n_char = 0;
	if (format_specifier == 'c')
		n_char += ft_printchar((char)va_arg(args, int));
	else if (format_specifier == 's')
		n_char += ft_printstr(va_arg(args, char *));
	else if (format_specifier == '%')
		n_char += ft_printchar('%');
	else if (format_specifier == 'd' || format_specifier == 'i')
		n_char += ft_printnbr(va_arg(args, int), "0123456789");
	else if (format_specifier == 'u')
		n_char += ft_printnbr_unsigned(va_arg(args, unsigned int),
				"0123456789");
	else if (format_specifier == 'x')
		n_char += ft_printnbr_unsigned(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (format_specifier == 'X')
		n_char += ft_printnbr_unsigned(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (format_specifier == 'p')
		n_char += ft_printptr(va_arg(args, long long unsigned int));
	return (n_char);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		n_char;

	i = 0;
	va_start(args, format);
	n_char = 0;
	while (format[i])
	{
		if (format[i] == '%')
			n_char += print_format(args, format[++i]);
		else
		{
			ft_putchar_fd(format[i], 1);
			n_char++;
		}
		i++;
	}
	va_end(args);
	return (n_char);
}
