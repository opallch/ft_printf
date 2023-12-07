/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oleung <oleung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:05:07 by oleung            #+#    #+#             */
/*   Updated: 2023/12/07 15:12:16 by oleung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putptr_fd(void *ptr, int fd)
{ 
    // NULL -> (nil)
    // else: 0x402004
    if (fd != -1)
    {
        if (!ptr)
            write(fd, "(nil)", 5 * sizeof(char));
        // TODO figure out how to print the address
        // else
        //     write(fd, );
    }
}