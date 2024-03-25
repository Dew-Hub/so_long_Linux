/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:39:16 by buonturk          #+#    #+#             */
/*   Updated: 2024/01/03 17:24:06 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*res;
	size_t	c;
	size_t	i;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (!str || len <= 0)
		return (NULL);
	if (len > str_len)
		len = str_len;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	c = start;
	i = 0;
	while (c < str_len && i < len)
	{
		res[i] = str[c];
		c++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	size_t	i;
	char	*tmp_str;

	if (!str1 || !str2)
		return (NULL);
	tmp_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!tmp_str)
		return (NULL);
	i = 0;
	while (*str1)
		tmp_str[i++] = *str1++;
	while (*str2)
		tmp_str[i++] = *str2++;
	tmp_str[i] = '\0';
	return (tmp_str);
}

char	*ft_strdup(const char *str)
{
	char	*tmp_str;
	int		c;

	c = 0;
	tmp_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!tmp_str)
		return (NULL);
	while (*str)
		tmp_str[c++] = *str++;
	tmp_str[c] = '\0';
	return (tmp_str);
}

void	*ft_free(char **tmp_ram, int next_line)
{
	char	*line;

	if (!*tmp_ram)
		return (NULL);
	if (next_line == 0)
	{
		if (*tmp_ram)
		{
			free(*tmp_ram);
			*tmp_ram = NULL;
		}
		return (NULL);
	}
	else if (next_line == 1)
	{
		line = ft_strdup(*tmp_ram);
		free(*tmp_ram);
		*tmp_ram = NULL;
		return (line);
	}
	return (NULL);
}
