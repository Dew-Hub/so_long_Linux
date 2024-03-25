/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:00:49 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/19 13:14:42 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "library/libft/libft.h"

void	sl_put_player(t_settings *game)
{
	int	height;
	int	width;

	height = -1;
	while (++height < game->map_height)
	{
		width = -1;
		while (game->map[height][++width])
		{
			if (game->map[height][width] == 'P')
			{
				game->player_x = width;
				game->player_y = height;
				return ;
			}
		}
	}
}

static char	**sl_copy_map(t_settings *game)
{
	char	**copy_map;
	int		i;

	copy_map = (char **)malloc(sizeof(char *) * (game->map_height));
	if (!copy_map)
	{
		ft_putstr_fd("Malloc error..!", 2);
		return (NULL);
	}
	i = 0;
	while (i < game->map_height)
	{
		copy_map[i] = ft_strdup(game->map[i]);
		if (!copy_map[i])
		{
			ft_putstr_fd("Malloc error..!", 2);
			return (NULL);
		}
		if (copy_map[i] == NULL)
			break ;
		i++;
	}
	return (copy_map);
}

static void	sl_path_find(char **copy_map, int *collect_count, int y, int x)
{
	if (copy_map[y][x] == 'C' || copy_map[y][x] == 'E')
		(*collect_count)++;
	if (copy_map[y][x] == 'E')
		copy_map[y][x] = '1';
	if (copy_map[y][x] == '1' || copy_map[y][x] == 'E')
		return ;
	copy_map[y][x] = '1';
	sl_path_find(copy_map, collect_count, y + 1, x);
	sl_path_find(copy_map, collect_count, y - 1, x);
	sl_path_find(copy_map, collect_count, y, x + 1);
	sl_path_find(copy_map, collect_count, y, x - 1);
}

static void	sl_copy_map_free(char **copy_map, t_settings *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		free(copy_map[i]);
		i++;
	}
	free(copy_map);
}

void	sl_path_check(t_settings *game, int y, int x)
{
	char	**copy_map;
	int		collectibles;

	collectibles = 0;
	copy_map = sl_copy_map(game);
	if (!copy_map)
		return ;
	sl_path_find(copy_map, &collectibles, y, x);
	if (collectibles != game->collectables + 1)
	{
		sl_copy_map_free(copy_map, game);
		ft_putstr_fd("Wrong Map..!!", 2);
		sl_map_error(game, 0);
	}
	sl_copy_map_free(copy_map, game);
}
