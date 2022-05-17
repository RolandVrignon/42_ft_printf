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

const char	*get_flag(va_list args, const char *c)
{
	if (*c == 'c')
		ft_flag_c(args);
	else if (*c == 's')
		ft_flag_s(args);
	else if (*c == 'p')
		ft_flag_p(args);
	else if (*c == 'd')
		ft_flag_d(args);
	else if (*c == 'i')
		printf("Flag = i");
	else if (*c == 'u')
		ft_flag_u(args);
	else if (*c == 'x')
		ft_flag_x(args);
	else if (*c == 'X')
		ft_flag_X(args);
	else if (*c == '%')
		ft_flag_pourcent();
	else
		return (NULL);
	return (c);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	int		len;
	
	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
			format = get_flag(args, format + 1);
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