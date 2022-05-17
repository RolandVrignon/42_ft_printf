/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 03:09:08 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/17 04:23:07 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_flag_c(va_list args)
{
    char a;
    
    a = va_arg(args, int);
    write(1, &a, 1);
}

void ft_flag_s(va_list args)
{
    char *a;
    
    a = va_arg(args, char *);
    ft_putstr_fd(a, 1);
}

void ft_flag_p(va_list args)
{
    // char *a;
    (void) args;
    // a = va_arg(args, char *);
    // ft_putstr_fd(a, 1);
}

void ft_flag_d(va_list args)
{
    char *a;
    
    a = ft_itoa(va_arg(args, int));
    ft_putstr_fd(a, 1);
    free(a);
}

void ft_flag_u(va_list args)
{
    char *a;
    int nbr;

    nbr = va_arg(args, int);
    if ( nbr < 0)
        ft_putstr_fd("4294967294", 1);
    else
    {
        a = ft_itoa(nbr);
        ft_putstr_fd(a, 1);
        free(a);
    }
}

