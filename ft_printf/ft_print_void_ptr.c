/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void_ptr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 12:39:27 by a1                #+#    #+#             */
/*   Updated: 2021/11/01 22:21:58 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_void_ptr(void *p)
{
	int	count;

	count = 0;
	ft_putstr_fd("0x", 1);
	count += 2;
	count += print_hexnum_p((unsigned long) p);
	return (count);
}
