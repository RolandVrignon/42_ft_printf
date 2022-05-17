/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:14:49 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/17 04:27:04 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

// # define PRINTF_VALID_FORMATS	"cspdiuxX\%"
# define HEXALOWER	"0123456789abcdef"
# define HEXAUPPER	"0123456789ABCDEF"

int		ft_printf(const char*, ...);

void	ft_flag_c(va_list args);

void	ft_flag_s(va_list args);

void	ft_flag_p(va_list args);

void	ft_flag_d(va_list args);

char	*ft_putnbr_base(int nbr, char *base, int j, char *r);

char	*ft_print_pointeur(unsigned long long nbr, char *base, char *str);

int		check_base(char *base);

void	ft_flag_p(va_list args);

void	ft_flag_i(va_list args);

void	ft_flag_u(va_list args);

void	ft_flag_x(va_list args);

void	ft_flag_X(va_list args);

void	ft_flag_pourcent();

#endif