/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:53:26 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/18 14:16:02 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_flag_uppercase_x(va_list args)
{
	char	*r;
	size_t	len;

	r = malloc(sizeof(char) * 40);
	r = ft_putnbr_base(va_arg(args, int), HEXAUPPER, 0, r);
	len = ft_strlen(r);
	ft_putstr_fd(r, 1);
	free(r);
	return (len);
}

size_t	ft_flag_pourcent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
