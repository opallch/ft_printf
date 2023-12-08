/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:42:05 by oleung            #+#    #+#             */
/*   Updated: 2023/12/08 16:13:44 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    size_t  i;
    va_list args;
    
    i = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%') // TODO why seg fault when format[i++]
        {
           i++; 
           if (format[i] == 'c')
            ft_putchar_fd((char) va_arg(args, int), 1);
           else if (format[i] == 's')
            ft_putstr_fd(va_arg(args, char *), 1);
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
                ft_putptr_fd(va_arg(args, void *), 1);
        }
        else
            ft_putchar_fd(format[i], 1);
        i++;
    }
    va_end(args);
    return (0);
}