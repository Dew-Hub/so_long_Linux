/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:57:21 by buonturk          #+#    #+#             */
/*   Updated: 2023/11/08 09:22:11 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int(int i)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (i == 0)
		return (write(1, "0", 1));
	if (i == -2147483648)
		return (write(1, "-2147483648", 11));
	if (i < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		leng++;
		i *= -1;
	}
	if (i >= 10)
	{
		tmp = ft_int(i / 10);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (write(1, &"0123456789"[i % 10], 1) == -1)
		return (-1);
	return (leng + 1);
}

int	ft_unsigned(unsigned int i)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (i >= 10)
	{
		tmp = ft_unsigned(i / 10);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (write(1, &"0123456789"[i % 10], 1) == -1)
		return (-1);
	return (leng + 1);
}

int	ft_string(char *str)
{
	int	i;

	i = -1;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[++i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
	}
	return (i);
}

int	ft_hex(unsigned int i, char c)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (i >= 16)
	{
		tmp = ft_hex(i / 16, c);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (c == 'X')
	{
		if (write(1, &"0123456789ABCDEF"[i % 16], 1) == -1)
			return (-1);
	}
	if (c == 'x')
	{
		if (write(1, &"0123456789abcdef"[i % 16], 1) == -1)
			return (-1);
	}
	return (leng + 1);
}

int	ft_point(unsigned long j, int i)
{
	int	leng;
	int	tmp;

	leng = 0;
	if (i == 1)
	{
		if (write(1, "0x", 2) == -1)
			return (-1);
		i = 0;
		leng += 2;
	}
	if (j >= 16)
	{
		tmp = ft_point(j / 16, i);
		if (tmp == -1)
			return (-1);
		leng += tmp;
	}
	if (write(1, &"0123456789abcdef"[j % 16], 1) == -1)
		return (-1);
	return (leng + 1);
}
