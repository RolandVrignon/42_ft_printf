/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:26:41 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/17 03:33:51 by rvrignon         ###   ########.fr       */
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

    int res = printf("string = %s char = %c manger : %d\n", test, manger[0], test_strlen(test));
    int res2 = ft_printf("string = %s char = %c manger : %d\n", test, manger[0], test_strlen(test));

    printf("Orignal : %d, ft_printf : %d", res, res2);

    return (0); 
}