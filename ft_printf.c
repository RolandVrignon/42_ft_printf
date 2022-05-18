/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:45:05 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/18 19:03:23 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_flag(va_list args, const char *c)
{
	size_t	len;

	if (!c)
		return (0);
	else if (*c == 'c')
		len = ft_flag_c(va_arg(args, int));
	else if (*c == 's')
		len = ft_flag_s(va_arg(args, char *));
	else if (*c == 'p')
		len = ft_flag_p(va_arg(args, void *));
	else if (*c == 'd')
		len = ft_flag_d(va_arg(args, int));
	else if (*c == 'i')
		len = ft_flag_d(va_arg(args, int));
	else if (*c == 'u')
		len = ft_flag_u(va_arg(args, unsigned int));
	else if (*c == 'x')
		len = ft_flag_x(va_arg(args, unsigned int));
	else if (*c == 'X')
		len = ft_flag_uppercase_x(va_arg(args, unsigned int));
	else if (*c == '%')
		len = ft_flag_pourcent();
	else
		return (0);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len += (get_flag(args, format + 1) - 1);
			format++;
		}
		else
			write(1, &*format, 1);
		if (!format)
		{
			va_end(args);
			return (len);
		}
		format++;
		len++;
	}
	va_end(args);
	return (len);
}
