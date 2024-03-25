/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:00:12 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/19 12:52:38 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "library/minilibx/mlx.h"
#include "library/libft/libft.h"

void	sl_images_check(t_settings *game)
{
	if (!game->up_xpm || !game->down_xpm
		|| !game->left_xpm || !game->right_xpm || !game->wall_xpm
		|| !game->exit_xpm || !game->collectable_xpm)
	{
		ft_putstr_fd("XPM file not found.!", 2);
		sl_exit(game);
	}
}

void	sl_import_images(t_settings *game)
{
	int	i;
	int	w;

	game->down_xpm = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/down.xpm", &i, &w);
	game->up_xpm = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/up.xpm", &i, &w);
	game->right_xpm = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/right.xpm", &i, &w);
	game->left_xpm = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/left.xpm", &i, &w);
	game->exit_xpm = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/portal.xpm", &i, &w);
	game->wall_xpm = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/wall.xpm", &i, &w);
	game->collectable_xpm = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/food.xpm", &i, &w);
	sl_images_check(game);
}

void	sl_add_graphics(t_settings *game)
{
	int	height;
	int	width;

	height = -1;
	mlx_clear_window(game->mlxpointer, game->winpointer);
	while (++height < game->map_height)
	{
		width = -1;
		while (game->map[height][++width])
		{
			if (game->map[height][width] == '1')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer,
					game->wall_xpm, width * UNIT, height * UNIT);
			if (game->map[height][width] == 'C')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer,
					game->collectable_xpm, width * UNIT, height * UNIT);
			if (game->map[height][width] == 'P')
				mlx_put_image_to_window(game->mlxpointer, game->winpointer,
					game->player, width * UNIT, height * UNIT);
			if (game->map[height][width] == 'E')
				mlx_put_image_to_window(game->mlxpointer,
					game->winpointer,
					game->exit_xpm, width * UNIT, height * UNIT);
		}
	}
}
