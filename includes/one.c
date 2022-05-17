/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 03:09:08 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/17 03:24:22 by rvrignon         ###   ########.fr       */
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
    int len;
    
    a = va_arg(args, char *);
    len = ft_strlen(a);
    write(1, &a, len);
}

void ft_flag_d(va_list args)
{
    char *a;
    int len;
    
    a = ft_itoa(va_arg(args, int));
    len = ft_strlen(a);
    write(1, &a, len);
}

