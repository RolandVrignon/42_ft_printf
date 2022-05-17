/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:45:05 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/17 03:00:10 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*get_flag(va_list args, const char *c)
{
	if (*c == 'c')
		printf("Flag = c");
	else if (*c == 's')
		printf("Flag = s");
	else if (*c == 'p')
		printf("Flag = p");
	else if (*c == 'd')
	{
		char *a = ft_itoa(va_arg(args, int));
		write(1, &a, ft_strlen(a));
	}
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
	c++;
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