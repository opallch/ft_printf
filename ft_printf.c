/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:42:05 by oleung            #+#    #+#             */
/*   Updated: 2023/12/07 14:04:02 by oleung           ###   ########.fr       */
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
        if (format[i] == '%')
        {
            /* 
            check format[i + 1]
            %
            d or i
            u
            x or X
            s
            p
            */
           if (format[i + 1] == 'c')
            ft_putchar_fd(va_arg(args, int), 0);
           i++; 
        }
        else
            ft_putchar_fd(format[i], 0);
        i++;
    }
    va_end(args);
    return (0);
}