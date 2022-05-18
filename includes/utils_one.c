/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:53:14 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/18 19:06:02 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_flag_c(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_flag_s(char *str)
{
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

size_t	ft_flag_p(void *p)
{
	char	*r;
	size_t	len;

	len = 0;
	ft_putstr_fd("0x", 1);
	r = malloc(sizeof(char) * 40);
	len = ft_print_pointeur((unsigned long long)p, HEXALOWER);
	free(r);
	return (len + 3);
}

size_t	ft_flag_d(int nb)
{
	char	*a;
	size_t	len;

	a = ft_itoa(nb);
	len = ft_strlen(a);
	ft_putstr_fd(a, 1);
	free(a);
	return (len);
}

size_t	ft_flag_u(unsigned int nb)
{
	char			*a;
	size_t			len;

	a = itoa_unsigned(nb);
	len = ft_strlen(a);
	ft_putstr_fd(a, 1);
	free(a);
	return (len);
	return (0);
}
