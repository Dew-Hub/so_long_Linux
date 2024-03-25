/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:59:24 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/19 12:11:01 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "library/minilibx/mlx.h"
#include "library/libft/libft.h"

void	sl_map_error(t_settings *game, int error_code)
{
	if (game->maplocation)
		free(game->maplocation);
	if (error_code == 1)
		ft_putstr_fd("Malloc error..!", 2);
	if (error_code == 2)
		ft_putstr_fd("Map doesn't covered by the Walls!", 2);
	if (error_code == 3)
		ft_putstr_fd("Line in text is Wrong..!", 2);
	exit (1);
}

void	sl_strfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	sl_images_free(t_settings *game)
{
	if (game->up_xpm)
		mlx_destroy_image(game->mlxpointer, game->up_xpm);
	if (game->down_xpm)
		mlx_destroy_image(game->mlxpointer, game->down_xpm);
	if (game->left_xpm)
		mlx_destroy_image(game->mlxpointer, game->left_xpm);
	if (game->right_xpm)
		mlx_destroy_image(game->mlxpointer, game->right_xpm);
	if (game->collectable_xpm)
		mlx_destroy_image(game->mlxpointer, game->collectable_xpm);
	if (game->exit_xpm)
		mlx_destroy_image(game->mlxpointer, game->exit_xpm);
	if (game->wall_xpm)
		mlx_destroy_image(game->mlxpointer, game->wall_xpm);
	game->player = NULL;
}

int	sl_exit(t_settings *game)
{
	int	line;

	line = 0;
	if (game->winpointer)
		mlx_destroy_window(game->mlxpointer, game->winpointer);
	while (line < game->map_height)
		free(game->map[line++]);
	if (game->map)
		free(game->map);
	free(game->maplocation);
	sl_images_free(game);
	exit(0);
}

void	sl_reset_tmp(t_settings *game)
{
	game->tmp.h = -1;
	game->tmp.w = -1;
}
