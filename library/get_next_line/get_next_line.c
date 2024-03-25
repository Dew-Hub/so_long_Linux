/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:31:58 by buonturk          #+#    #+#             */
/*   Updated: 2024/01/03 16:56:38 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h> 

static char	*ft_merge_str(char *static_str, char *buf_str)
{
	char	*new_str;

	new_str = 0;
	if (!static_str && buf_str)
	{
		new_str = ft_strdup(buf_str);
		if (!new_str)
			return (NULL);
		return (new_str);
	}
	new_str = ft_strjoin(static_str, buf_str);
	ft_free(&static_str, 0);
	return (new_str);
}

static int	ft_check_newline(char *str)
{
	size_t	c;

	if (!str)
		return (0);
	c = 0;
	while (str[c] != '\0')
	{
		if (str[c] == '\n')
			return (1);
		c++;
	}
	return (0);
}

static char	*ft_full_line(char *static_str)
{
	char	*line;
	size_t	c;
	size_t	i;

	c = 0;
	while (static_str[c] != '\n')
		c++;
	line = malloc(sizeof(char) * (c + 2));
	if (!line)
		return (0);
	i = 0;
	while (i < c + 1)
	{
		line[i] = static_str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_next_line_str(char *static_str)
{
	char	*new_str;
	size_t	c;

	c = 0;
	while (static_str[c] != '\n')
		c++;
	if (static_str[c + 1] == '\0')
		return (ft_free(&static_str, 0));
	new_str = ft_substr(static_str, c + 1, ft_strlen(static_str));
	ft_free(&static_str, 0);
	if (!new_str)
		return (NULL);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		buf_str[BUFFER_SIZE + 1];
	long		read_byt;
	static char	*static_str = NULL;
	char		*copy_line;

	copy_line = 0;
	read_byt = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(&static_str, 0));
	while (read_byt > 0)
	{
		read_byt = read(fd, buf_str, BUFFER_SIZE);
		if ((read_byt <= 0 && !static_str) || read_byt == -1)
			return (ft_free(&static_str, 0));
		buf_str[read_byt] = '\0';
		static_str = ft_merge_str(static_str, buf_str);
		if (ft_check_newline(static_str))
		{
			copy_line = ft_full_line(static_str);
			if (!copy_line)
				return (ft_free(&static_str, 0));
			return (static_str = ft_next_line_str(static_str), copy_line);
		}
	}
	return (ft_free(&static_str, 1));
}
