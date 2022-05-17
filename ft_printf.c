/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:45:05 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/17 04:26:58 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_flag(va_list args, const char *c)
{
	size_t len;
	
	if (*c == 'c')
		len = ft_flag_c(args);
	else if (*c == 's')
		len = ft_flag_s(args);
	else if (*c == 'p')
		len = ft_flag_p(args);
	else if (*c == 'd')
		len = ft_flag_d(args);
	else if (*c == 'i')
		len = ft_flag_d(args);
	else if (*c == 'u')
		len = ft_flag_u(args);
	else if (*c == 'x')
		len = ft_flag_x(args);
	else if (*c == 'X')
		len = ft_flag_X(args);
	else if (*c == '%')
		len = ft_flag_pourcent();
	else
		return (0);
	return (len);
}

int ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		len;
	
	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len += get_flag(args, format + 1) - 1;
			format++;
		}
		else
			write(1, &*format, 1);
		if (!format)
		{
			va_end(args);
			return(len);
		}
		format++;
		len++;
	}
	va_end(args);
	return (len);
}