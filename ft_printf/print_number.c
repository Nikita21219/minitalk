/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:36:41 by a1                #+#    #+#             */
/*   Updated: 2021/11/01 19:48:55 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_number(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (0);
	if (nb == -2147483648)
	{
		count++;
		nb /= 10;
	}
	if (nb < 0)
	{
		count++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count - 1);
}

int	print_number(int nb)
{
	ft_putnbr_fd(nb, 1);
	return (len_number(nb));
}
