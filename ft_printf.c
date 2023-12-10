/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:42:05 by oleung            #+#    #+#             */
/*   Updated: 2023/12/10 09:57:31 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    size_t  i;
    va_list args;
    int n_char;
    
    i = 0;
    va_start(args, format);
    n_char = 0;    
    while (format[i])
    {
        if (format[i] == '%') // TODO why seg fault when format[i++]
        {
           i++; 
           if (format[i] == 'c')
            n_char += ft_printchar((char) va_arg(args, int));
           else if (format[i] == 's')
            n_char += ft_printstr(va_arg(args, char *));
            else if (format[i] == '%')
                n_char += ft_printchar('%');
            else if (format[i] == 'd' || format[i] == 'i')
                n_char += ft_printnbr(va_arg(args, int), "0123456789");
            else if (format[i] == 'u')
                n_char += ft_printnbr_unsigned(va_arg(args, unsigned int), "0123456789");
            else if (format[i] == 'x')
                n_char += ft_printnbr_unsigned(va_arg(args, unsigned int), "0123456789abcdef");
            else if (format[i] == 'X')
                n_char += ft_printnbr_unsigned(va_arg(args, unsigned int), "0123456789ABCDEF");
            else if (format[i] == 'p')
                n_char += ft_printptr(va_arg(args, long long unsigned int));
        }
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