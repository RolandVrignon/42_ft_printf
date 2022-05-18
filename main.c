/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:26:41 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/18 17:29:36 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "limits.h"

int	test_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &i, 1);
		i++;
	}
	return (i);
}

int	main(void)
{
	char			*manger;
	char			*test;
	unsigned int	nonsigne;
	int				resiii;
	int				res;

	manger = "Hello";
	test = "four";
	nonsigne = 67;
	resiii = printf("c = %c || s = %s || d : %d || i : %i || p = %p || u = %u || x : %x || X : %X || Pourcent : %%\n", manger[0], test, -30, -80, test, nonsigne, 255, 255);
	res = ft_printf("c = %c || s = %s || d : %d || i : %i || p = %p || u = %u || x : %x || X : %X || Pourcent : %%\n", manger[0], test, -30, -80, test, nonsigne, 255, 255);
	printf("Orignal : %d, ft_printf : %d", resiii, res);
	return (0);
}
