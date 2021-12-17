/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bclarind <bclarind@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:01:36 by bclarind          #+#    #+#             */
/*   Updated: 2021/11/08 13:25:49 by bclarind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		ft_putchar_fd(*str++, 1);
		count++;
	}
	return (count - 1);
}

int	print_null(char *s)
{
	s = "(null)";
	ft_putstr_fd(s, 1);
	return (5);
}

int	print_conversions(const char *input, va_list ap)
{
	int		count;
	char	*str;

	count = 0;
	if (*input == 'd' || *input == 'i')
		count += print_number(va_arg(ap, int));
	else if (*input == 'u')
		count += print_unsigned_number(va_arg(ap, unsigned int));
	else if (*input == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (*input == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			count += print_null(str);
		else
			count += print_str(str);
	}
	else if (*input == 'x' || *input == 'X')
		count += print_hexnum(va_arg(ap, int), input);
	else if (*input == 'p')
		count += ft_print_void_ptr(va_arg(ap, void *));
	else if (*input == '%')
		ft_putchar_fd('%', 1);
	return (count);
}

int	main_logic(const char *input, va_list ap, int count)
{
	while (*input)
	{
		if (*input == '%' && *++input)
			count += print_conversions(input, ap);
		else
			ft_putchar_fd(*input, 1);
		input++;
		count++;
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int		count;
	va_list	ap;

	if (input == NULL)
		return (-1);
	count = 0;
	va_start(ap, input);
	count += main_logic(input, ap, count);
	va_end(ap);
	return (count);
}
