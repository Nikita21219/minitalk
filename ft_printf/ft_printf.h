/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:01:41 by bclarind          #+#    #+#             */
/*   Updated: 2021/11/01 22:26:32 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include "libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *input, ...);
int		print_hexnum(unsigned int num, const char *input);
int		print_hexnum_p(unsigned long num);
int		ft_print_void_ptr(void *p);
int		print_number(int nb);
int		print_unsigned_number(unsigned int nb);

#endif