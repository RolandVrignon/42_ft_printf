/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:45:05 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/17 03:21:55 by rvrignon         ###   ########.fr       */
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
		printf("Flag = p");
	else if (*c == 'd')
		ft_flag_d(args);
	else if (*c == 'i')
		printf("Flag = i");
	else if (*c == 'u')
		printf("Flag = u");
	else if (*c == 'x')
		printf("Flag = x");
	else if (*c == 'X')
		printf("Flag = X");
	else if (*c == '%')
		printf("Flag = Hey");
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