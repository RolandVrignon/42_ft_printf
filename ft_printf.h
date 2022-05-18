/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvrignon <rvrignon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:14:49 by rvrignon          #+#    #+#             */
/*   Updated: 2022/05/18 19:07:31 by rvrignon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

// # define PRINTF_VALID_FORMATS	"cspdiuxX\%"
# define HEXALOWER	"0123456789abcdef"
# define HEXAUPPER	"0123456789ABCDEF"

int		ft_printf(const char *format, ...);

// Flags

size_t	ft_flag_c(int c);

size_t	ft_flag_s(char *str);

size_t	ft_flag_p(void *p);

size_t	ft_flag_d(int nb);

size_t	ft_flag_u(unsigned int nb);

size_t	ft_flag_x(unsigned int nb);

size_t	ft_flag_uppercase_x(unsigned int nb);

size_t	ft_flag_pourcent(void);

// Utils

char	*ft_putnbr_base(unsigned int nbr, char *base, int j, char *r);

size_t	ft_print_pointeur(unsigned long long nbr, char *base);

int		check_base(char *base);

void	ft_strrev(char *str);

char	*process_unsigned(int j, int len, char *str, unsigned int n);

char	*itoa_unsigned(unsigned int n);

#endif