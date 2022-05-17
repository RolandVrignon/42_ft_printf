/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:26:41 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/17 04:40:04 by rvrignon         ###   ########.fr       */
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
    unsigned int nonsigne = 67;

    int resiii = printf("char = %c || string = %s || decimal : %d || non signe = %u || hexa : %x || HEXA : %X || Pourcent : %%\n", manger[0], test, -30, nonsigne, 255, 255);
    int res = ft_printf("char = %c || string = %s || decimal : %d || non signe = %u || hexa : %x || HEXA : %X || Pourcent : %%\n", manger[0], test, -30, nonsigne, 255, 255);

    printf("Orignal : %d, ft_printf : %d", resiii, res);

    return (0); 
}