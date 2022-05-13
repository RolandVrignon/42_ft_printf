/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:26:41 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/13 23:30:52 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main()
{
    char *manger = "Hello";

    ft_printf("manger : %ld\n", ft_strlen(manger));
    printf("manger : %ld", ft_strlen(manger));

    return (0); 
}