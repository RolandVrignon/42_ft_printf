/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:45:05 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/18 19:58:29 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flag(va_list args, const char *c)
{
	int	len;

	if (!c)
		len = -1;
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
		len = -1;
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		len;
	int			status;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			status = get_flag(args, format + 1);
			if (status == -1)
				break ;
			else
				len += status - 1;
			format++;
		}
		else
			write(1, &*format, 1);
		format++;
		len++;
	}
	va_end(args);
	return (len);
}

// int	main(void)
// {
// 	char			*manger;
// 	char			*test;
// 	unsigned int	nonsigne;
// 	int				resiii;
// 	int				res;

// 	manger = "Hello";
// 	test = "four";
// 	nonsigne = 67;
// 	resiii = printf("c = %c || s = %s || d : %d || i : %i || p = %p || u = %u || x : %x || X : %X || Pourcent : %%\n", manger[0], test, -30, -80, test, nonsigne, 255, 255);
// 	res = ft_printf("c = %c || s = %s || d : %d || i : %i || p = %p || u = %u || x : %x || X : %X || Pourcent : %%\n", manger[0], test, -30, -80, test, nonsigne, 255, 255);
// 	printf("printf : %d, ft_printf : %d", resiii, res);
// 	return (0);
// }