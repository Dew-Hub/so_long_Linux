/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playercontrols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 23:00:57 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/19 10:59:17 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "so_long.h"
#include "library/printf/ft_printf.h"
#include "library/minilibx/mlx.h"
#include "library/libft/libft.h"

static int	sl_print_screen(t_settings *game, char *s, char *c)
{
	char	*str_step;
	char	*str_coin;

	s = ft_itoa(game->counter);
	c = ft_itoa(game->collectables);
	str_step = ft_strjoin("Step : ", s);
	str_coin = ft_strjoin("Coin : ", c);
	if (!s || !c || !str_step || !str_coin)
	{
		if (s)
			free(s);
		if (c)
			free(c);
		if (str_step)
			free(str_step);
		if (str_coin)
			free(str_coin);
		return (ft_putstr_fd("Print Screen Error!", 2), sl_exit(game), 0);
	}
	mlx_string_put(game->mlxpointer, game->winpointer,
		20, 15, 0xFFFFF, str_step);
	mlx_string_put(game->mlxpointer, game->winpointer,
		20, 25, 0xFFFFF, str_coin);
	return (free(str_coin), free(str_step), free(s), free(c), 0);
}

static int	sl_set_player_(t_settings *game, int h, int w)
{
	if (game->map[h][w] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("YOU WIN..!\n");
		sl_exit(game);
	}
	if (game->map[h][w] == 'C')
		game->collectables--;
	game->map[h][w] = 'P';
	game->player_x = w;
	game->player_y = h;
	game->counter++;
	return (1);
}

static int	sl_input_w_s(t_settings *game, int input)
{
	game->tmp.w = game->player_x;
	game->tmp.h = game->player_y;
	if (input == W)
	{
		if (game->map[--game->tmp.h][game->tmp.w] == '1')
			return (0);
		game->tmp.i = sl_set_player_(game, game->tmp.h, game->tmp.w);
		if (!game->tmp.i)
			return (0);
		game->map[game->tmp.h + 1][game->tmp.w] = '0';
		game->player = game->up_xpm;
	}
	else if (input == S)
	{
		if (game->map[++game->tmp.h][game->tmp.w] == '1')
			return (0);
		game->tmp.i = sl_set_player_(game, game->tmp.h, game->tmp.w);
		if (!game->tmp.i)
			return (0);
		game->map[game->tmp.h - 1][game->tmp.w] = '0';
		game->player = game->down_xpm;
	}
	ft_printf("Step Count: %d\n", game->counter);
	ft_printf("Left Coins: %d\n", game->collectables);
	return (1);
}

static int	sl_input_a_d(t_settings *game, int input)
{
	game->tmp.w = game->player_x;
	game->tmp.h = game->player_y;
	if (input == A)
	{
		if (game->map[game->tmp.h][--game->tmp.w] == '1')
			return (0);
		game->tmp.i = sl_set_player_(game, game->tmp.h, game->tmp.w);
		if (!game->tmp.i)
			return (0);
		game->map[game->tmp.h][game->tmp.w + 1] = '0';
		game->player = game->left_xpm;
	}
	else if (input == D)
	{
		if (game->map[game->tmp.h][++game->tmp.w] == '1')
			return (0);
		game->tmp.i = sl_set_player_(game, game->tmp.h, game->tmp.w);
		if (!game->tmp.i)
			return (0);
		game->map[game->tmp.h][game->tmp.w - 1] = '0';
		game->player = game->right_xpm;
	}
	ft_printf("Step Count: %d\n", game->counter);
	ft_printf("Left Coins: %d\n", game->collectables);
	return (1);
}

int	sl_game_working(int command, t_settings *game)
{
	int	checker;

	if (command == ESC)
		sl_exit(game);
	if (command == W)
		checker = sl_input_w_s(game, command);
	if (command == S)
		checker = sl_input_w_s(game, command);
	if (command == A)
		checker = sl_input_a_d(game, command);
	if (command == D)
		checker = sl_input_a_d(game, command);
	if (checker)
		sl_add_graphics(game);
	sl_print_screen(game, 0, 0);
	return (1);
}
