/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexnum_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1 <a1@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:44:06 by a1                #+#    #+#             */
/*   Updated: 2021/11/01 19:30:00 by a1               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_symbol_p(unsigned long mod)
{
	if (mod == 10)
		return ('a');
	else if (mod == 11)
		return ('b');
	else if (mod == 12)
		return ('c');
	else if (mod == 13)
		return ('d');
	else if (mod == 14)
		return ('e');
	else if (mod == 15)
		return ('f');
	return (0);
}

char	print_digit_p(unsigned long mod)
{
	if (mod >= 0 && mod <= 9)
		return (mod + 48);
	else if (mod >= 10)
		return (get_symbol_p(mod));
	return (0);
}

size_t	count_number_p(unsigned long number)
{
	size_t	count;

	count = 0;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_strrev_p(char *str)
{
	char	*strrev;
	char	*res;
	int		i;

	strrev = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	res = strrev;
	i = ft_strlen(str);
	while (i)
		*strrev++ = str[--i];
	return (res);
}

int	print_hexnum_p(unsigned long num)
{
	int		count;
	int		mod;
	char	*res;
	char	*begin_res;
	char	*strrev;

	count = 0;
	res = ft_calloc(count_number_p(num) + 1, sizeof(char));
	begin_res = res;
	if (num == 0 && count++ > -1)
		ft_putchar_fd('0', 1);
	while (num != 0)
	{
		mod = num % 16;
		num /= 16;
		if (mod < 16)
			*res++ = print_digit_p(mod);
		count++;
	}
	strrev = ft_strrev_p(begin_res);
	ft_putstr_fd(strrev, 1);
	free(strrev);
	free(begin_res);
	return (count - 1);
}
