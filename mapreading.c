/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapreading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:00:53 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/19 10:55:13 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long.h"
#include "library/get_next_line/get_next_line.h"
#include "library/libft/libft.h"

int	sl_map_wall_check(t_settings *game)
{
	int	h;
	int	w;
	int	width;
	int	height;

	h = 0;
	w = 0;
	width = game->map_width - 1;
	height = game->map_height - 1;
	while (h <= height)
	{
		if (game->map[h][0] != '1' || game->map[h][width] != '1')
			return (sl_map_error(game, 2), 0);
		h++;
	}
	while (w <= width)
	{
		if (game->map[0][w] != '1' || game->map[height][w] != '1')
			return (sl_map_error(game, 2), 0);
		w++;
	}
	return (1);
}

static int	sl_line_check(t_settings *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (i != game->map_width)
		return (1);
	return (0);
}

void	sl_map_loading(t_settings *game)
{
	int		c;
	int		fd;
	char	*line;

	c = 0;
	game->map = (char **)malloc(sizeof(char *) * game->map_height);
	if (!game->map)
		sl_map_error(game, 1);
	fd = open(game->maplocation, O_RDONLY);
	while (c < game->map_height)
	{
		line = get_next_line(fd);
		if (sl_line_check(game, line))
			return (free(line), close(fd), sl_map_error(game, 3));
		game->map[c] = ft_strdup(line);
		if (game->map[c] == NULL)
			return (free(line), close(fd), sl_strfree(game->map));
		free (line);
		c++;
	}
	close(fd);
}

static int	sl_width_measure(char *str)
{
	int	width;

	width = 0;
	while (str[width] != '\n' && str[width] != '\0')
		width++;
	return (width);
}

int	sl_map_read(t_settings *game)
{
	int		fd;
	char	*line;

	game->tmp.h = 0;
	game->tmp.w = 0;
	fd = open(game->maplocation, O_RDONLY);
	line = get_next_line(fd);
	if (!line || line[game->tmp.h] == 32
		|| line[game->tmp.h] == '\t')
		return (free(line), close(fd), ft_putstr_fd("Map is empty..!", 2), 0);
	game->tmp.w = sl_width_measure(line);
	while (line)
	{
		free(line);
		game->tmp.h++;
		line = get_next_line(fd);
	}
	game->map_height = game->tmp.h;
	game->map_width = game->tmp.w;
	close(fd);
	return (1);
}
