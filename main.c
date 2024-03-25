/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:00:16 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/19 12:53:45 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "library/libft/libft.h"
#include "library/minilibx/mlx.h"

int	main(int argc, char **argv)
{
	t_settings	game;

	if (argc == 2)
	{
		if (sl_map_name_check(argv[1], &game) == 0)
			sl_map_error(&game, 0);
		if (sl_map_read(&game) == 0)
			sl_map_error(&game, 0);
		sl_map_loading(&game);
		sl_map_wall_check(&game);
		game.collectables = 0;
		sl_map_values_check(&game);
		sl_path_check(&game, game.player_y, game.player_x);
		game.mlxpointer = mlx_init();
		game.winpointer = mlx_new_window(game.mlxpointer,
				(game.map_width * UNIT), (game.map_height * UNIT), "so_long");
		sl_import_images(&game);
		game.player = game.right_xpm;
		sl_add_graphics(&game);
		mlx_hook(game.winpointer, 17, XMASK, (void *)exit, 0);
		game.counter = 0;
		mlx_hook(game.winpointer, 2, XMASK, sl_game_working, &game);
		return (mlx_loop(game.mlxpointer), 1);
	}
	ft_putstr_fd("Error..!\nWrong Argument..!", 2);
}
