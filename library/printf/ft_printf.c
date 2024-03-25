/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:57:27 by buonturk          #+#    #+#             */
/*   Updated: 2023/11/08 09:22:13 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		leng;
	int		counter;
	int		tmp;

	counter = -1;
	leng = 0;
	va_start(args, str);
	while (str[++counter] != '\0')
	{
		if (str[counter] == '%' && ft_check(str[counter + 1]))
		{
			tmp = ft_format(&args, str[++counter]);
			if (tmp == -1)
				return (-1);
			leng += tmp - 1;
		}
		else if (str[counter] != '%' && ft_putchar(str[counter]) == -1)
			return (-1);
		leng++;
	}
	va_end(args);
	return (leng);
}

int	ft_check(char c)
{
	if (c == 'c' || c == 'd' || c == 'i' || c == 'u' || c == '%'
		|| c == 's' || c == 'x' || c == 'X' || c == 'p')
		return (1);
	return (0);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_format(va_list *args, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (c == '%')
		return (ft_putchar('%'));
	else if (c == 'd' || c == 'i')
		return (ft_int(va_arg((*args), int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg((*args), unsigned int)));
	else if (c == 's')
		return (ft_string(va_arg((*args), char *)));
	else if (c == 'X' || c == 'x')
		return (ft_hex(va_arg((*args), unsigned int), c));
	else if (c == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else
		return (0);
}
