/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:53:23 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/18 14:16:07 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int		i;
	long	nb;
	char	test;

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

size_t	ft_print_pointeur(unsigned long long nbr, char *base)
{
	size_t				base_len;
	size_t				i;
	unsigned long long	copy;

	i = 0;
	copy = nbr;
	while (copy >= 16)
	{	
		copy /= 16;
		i++;
	}
	base_len = ft_strlen(base);
	while (nbr >= 16)
	{
		ft_print_pointeur((nbr / base_len), HEXALOWER);
		nbr = nbr % base_len;
	}
	write(1, &base[nbr], 1);
	return (i);
}

size_t	ft_flag_x(va_list args)
{
	char	*r;
	char	*a;
	size_t	len;

	r = malloc(sizeof(char) * 40);
	a = ft_putnbr_base(va_arg(args, int), HEXALOWER, 0, r);
	len = ft_strlen(a);
	ft_putstr_fd(a, 1);
	// free (r);
	return (len);
}