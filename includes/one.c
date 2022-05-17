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

size_t ft_flag_c(va_list args)
{
    char a;
    
    a = va_arg(args, int);
    write(1, &a, 1);
    return (1);
}

size_t ft_flag_s(va_list args)
{
    char *a;
    
    a = va_arg(args, char *);
    ft_putstr_fd(a, 1);
    return(ft_strlen(a));
}

size_t ft_flag_p(va_list args)
{
    char    *r;
    size_t  len;

    len = 0;
    ft_putstr_fd("0x", 1);
    r = malloc(sizeof(char) * 40);
    len = ft_print_pointeur(va_arg(args, unsigned long long int), HEXALOWER);
    free(r);
    return (len + 3);
}

size_t ft_flag_d(va_list args)
{
    char *a;
    size_t len;
    
    a = ft_itoa(va_arg(args, int));
    len = ft_strlen(a);
    ft_putstr_fd(a, 1);
    free(a);
    return(len);
}

size_t ft_flag_u(va_list args)
{
    char *a;
    int nbr;
    size_t len;

    nbr = va_arg(args, int);
    if ( nbr < 0)
    {
        ft_putstr_fd("4294967294", 1);
        return (10);
    }
    else
    {
        a = ft_itoa(nbr);
        len = ft_strlen(a);
        ft_putstr_fd(a, 1);
        free(a);
        return(len);
    }
    return (0);
}

