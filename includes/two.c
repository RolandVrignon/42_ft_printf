/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 03:42:50 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/17 04:01:58 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+' || base[i] <= ' ')
			return (0);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

char	*ft_putnbr_base(int nbr, char *base, int j, char *r)
{
	int			i;
	long		nb;
	char		test;

	i = check_base(base);
	nb = nbr;
	if (i == 0)
		return (0);
	if (nb < 0)
	{
		nb = nb * -1;
		r[j] = '-';
		j = j + 1;
	}
	if (nb < i && nb >= 0)
	{
		test = base[nb];
		r[j] = test;
	}
	if (nb >= i)
	{
		ft_putnbr_base((nb / i), base, j + 1, r);
		ft_putnbr_base((nb % i), base, j, r);
	}
	return (r);
}

void ft_flag_x(va_list args)
{
    char *r;
    char *a;
    
    r = malloc(sizeof(char) * 40);
    a = ft_putnbr_base(va_arg(args, int), HEXALOWER, 0, r);
    ft_putstr_fd(a, 1);
    free (r);
}

void ft_flag_X(va_list args)
{
    char *r;
    char *a;
    
    r = malloc(sizeof(char) * 40);
    a = ft_putnbr_base(va_arg(args, int), HEXAUPPER, 0, r);
    ft_putstr_fd(a, 1);
    free(r);
}