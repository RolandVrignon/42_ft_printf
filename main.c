/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:26:41 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/17 04:06:28 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int test_strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        write(1, &i, 1);
        i++;
    }
    return (i);
}

int main()
{
    char *manger = "Hello";
    char *test = "four";

    int resiii = printf("char = %c || string = %s || decimal : %d || hexa : %x || HEXA : %X\n", manger[0], test, test_strlen(test), 255, 255);
    int res = ft_printf("char = %c || string = %s || decimal : %d || hexa : %x || HEXA : %X\n", manger[0], test, test_strlen(test), 255, 255);

    printf("Orignal : %d, ft_printf : %d", resiii, res);

    return (0); 
}