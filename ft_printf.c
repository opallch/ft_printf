/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:42:05 by oleung            #+#    #+#             */
/*   Updated: 2023/12/09 11:43:09 by oleung           ###   ########.fr       */
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
                ft_putchar_fd('%', 1);
            else if (format[i] == 'd' || format[i] == 'i')
                ft_putnbr_fd(va_arg(args, int), 1);
            else if (format[i] == 'u')
                ft_putnbr_fd(va_arg(args, unsigned int), 1);
            else if (format[i] == 'x')
                ft_putnbr_base_fd(va_arg(args, int), "0123456789abcdef", 1);
            else if (format[i] == 'X')
                ft_putnbr_base_fd(va_arg(args, int), "0123456789ABCDEF", 1);
            else if (format[i] == 'p')
                ft_putptr_fd(va_arg(args, long long unsigned int), 1);
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