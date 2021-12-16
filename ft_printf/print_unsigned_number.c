/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_number.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:45:02 by a1                #+#    #+#             */
/*   Updated: 2021/11/01 19:48:35 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_unsigned_number(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (0);
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count - 1);
}

void	ft_put_unsigned_nbr_fd(unsigned int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + 48, fd);
	}
}

int	print_unsigned_number(unsigned int nb)
{
	ft_put_unsigned_nbr_fd(nb, 1);
	return (len_unsigned_number(nb));
}
