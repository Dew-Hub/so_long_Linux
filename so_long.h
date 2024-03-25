/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buonturk <buonturk@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 03:04:57 by buonturk          #+#    #+#             */
/*   Updated: 2024/03/19 12:54:14 by buonturk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define UNIT 32
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define XMASK 1L<<0

typedef struct s_tmp
{
	int	i;
	int	w;
	int	h;
}	t_tmp;

typedef struct s_game
{
	int		map_height;
	int		map_width;
	int		collectables;
	int		counter;
	int		player_x;
	int		player_y;

	char	**map;
	char	*maplocation;

	void	*player;
	void	*up_xpm;
	void	*down_xpm;
	void	*right_xpm;
	void	*left_xpm;
	void	*wall_xpm;
	void	*exit_xpm;
	void	*collectable_xpm;
	void	*mlxpointer;
	void	*winpointer;
	t_tmp	tmp;
}	t_settings;

int		sl_exit(t_settings *game);
int		sl_game_working(int command, t_settings *game);

void	sl_map_ber_check(char *mapname);
int		sl_map_name_check(char *mapname, t_settings *game);
int		sl_map_wall_check(t_settings *game);
void	sl_map_loading(t_settings *game);
int		sl_map_read(t_settings *game);
void	sl_map_error(t_settings *game, int error_code);
void	sl_import_images(t_settings *game);
void	sl_images_check(t_settings *game);
void	sl_path_check(t_settings *game, int x, int y);
void	sl_add_graphics(t_settings *game);
void	sl_put_player(t_settings *game);
int		sl_map_values_check(t_settings *game);
void	sl_reset_tmp(t_settings *game);
void	sl_images_free(t_settings *game);
int		sl_bug_check(t_settings *game, int p, int e);
void	sl_strfree(char **str);

#endif
