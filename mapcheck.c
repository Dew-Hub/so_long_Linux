/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:00:44 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/19 12:54:17 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "so_long.h"
#include "library/libft/libft.h"

int	sl_bug_check(t_settings *game, int p, int e)
{
	if (p != 1 || e != 1 || game->collectables == 0)
		return (ft_putstr_fd("Missing or excess entries!", 2)
			, sl_map_error(game, 0), 0);
	return (1);
}

int	sl_map_values_check(t_settings *game)
{
	int	p;
	int	e;

	p = 0;
	e = 0;
	sl_reset_tmp(game);
	while (++game->tmp.h < game->map_height)
	{
		game->tmp.w = -1;
		while (game->map[game->tmp.h][++game->tmp.w])
		{
			if (game->map[game->tmp.h][game->tmp.w] == 'P')
				p++;
			else if (game->map[game->tmp.h][game->tmp.w] == 'E')
				e++;
			else if (game->map[game->tmp.h][game->tmp.w] == 'C')
				game->collectables++;
			else if (game->map[game->tmp.h][game->tmp.w] != '1'
				&& game->map[game->tmp.h][game->tmp.w] != '0'
				&& game->map[game->tmp.h][game->tmp.w] != '\n')
				return (ft_putstr_fd("Unknown value on the map!", 2)
					, sl_map_error(game, 0), 0);
		}
	}
	return (sl_bug_check(game, p, e), sl_put_player(game), 1);
}

void	sl_map_ber_check(char *mapname)
{
	int	len;

	len = ft_strlen(mapname);
	if (mapname[len - 1] != 'r' || mapname[len - 2] != 'e'
		|| mapname[len - 3] != 'b' || mapname[len - 4] != '.')
	{
		ft_putstr_fd("False .ber extension..!!", 2);
		exit (1);
	}
}

static int	sl_map_check_fd(t_settings *game)
{
	int	fd;

	fd = open(game->maplocation, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		return (ft_putstr_fd("Map not found!", 2), 0);
	}
	close(fd);
	return (1);
}

int	sl_map_name_check(char *mapname, t_settings *game)
{
	sl_map_ber_check(mapname);
	game->maplocation = ft_strjoin("map/", mapname);
	if (!game->maplocation)
		return (ft_putstr_fd("Map Error", 2), 0);
	if (sl_map_check_fd(game) == 0)
		return (0);
	return (1);
}
