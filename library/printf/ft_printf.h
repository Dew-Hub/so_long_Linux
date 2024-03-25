/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 22:57:32 by buonturk          #+#    #+#             */
/*   Updated: 2023/11/08 09:22:16 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_format(va_list *args, char c);
int	ft_int(int i);
int	ft_unsigned(unsigned int i);
int	ft_string(char *str);
int	ft_hex(unsigned int i, char c);
int	ft_point(unsigned long j, int i);
int	ft_check(char c);
#endif
