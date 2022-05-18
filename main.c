/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:26:41 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/18 16:54:27 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "limits.h"

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
    // char *manger = "Hello";
    // char *test = "four";
    // unsigned int nonsigne = 67;

    // int resiii = printf("c = %c || s = %s || d : %d || i : %i || p = %p || u = %u || x : %x || X : %X || Pourcent : %%\n", manger[0], test, -30, -80, test, nonsigne, 255, 255);
    // int res = ft_printf("c = %c || s = %s || d : %d || i : %i || p = %p || u = %u || x : %x || X : %X || Pourcent : %%\n", manger[0], test, -30, -80, test, nonsigne, 255, 255);
    int resiii = printf("%u\n", -99);
    int res = ft_printf("%u\n", -99);

    printf("Orignal : %d, ft_printf : %d", resiii, res);

    return (0); 
}