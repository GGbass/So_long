/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:10:34 by marvin            #+#    #+#             */
/*   Updated: 2024/10/29 23:00:22 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define X 17
# define RIGHT_D 100
# define LEFT_A 97
# define UP_W 119
# define DOWN_S 115
# define UP_ARROW 65362
# define DOWN_ARROW 65364
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307

typedef struct s_sprites
{
	void	*c;
	void	*e;
	void	*p1;
	void	*p2;
	void	*p3;
	void	*w;
	void	*n;
	void	*bg;
}			t_sprites;

typedef struct s_map
{
	int		x;
	int		y;
	int		collect;
	int		exit;
	int		player;
}			t_map;

typedef struct s_data
{
	int			width;
	int			update;
	int			height;
	void		*mlx;
	void		*mlx_window;
	int			pacman;
	int			fd;
	int			moves;
	int			n_flag;
	int			ghost_x;
	int			ghost_y;
	int			pos_x;
	int			pos_y;
	int			exit_x;
	int			exit_y;
	int			exit_flag;
	char		**map;
	char		**run_map;
	t_sprites	*img;
	t_map		*m_map;
}			t_data;

int		check_chars(char **map);
int		available_char(char c);
void	loading(t_data *data, t_sprites *img);
int		data_destroyer(t_data *data);
void	check_exit(t_data *data, int x, int y);
int		game_conditions(t_data *data);
void	check_collect(t_data *data, int x, int y);
int		check(t_data *data, int argc, char **argv);
void	free_array(char **array1, char **array2);
int		check_items(t_data *data, char **map);
void	flood_fill(t_data *data, int x, int y);
void	find_player(t_data *data);
void	update_location(t_data *data, int x, int y);
void	drawing(t_data *data);
int		check_argv(int argc, char **argv);
int		update(t_data *data);
void	find_ghost(t_data *data);
void	ghost_location(t_data *data, int x, int y);
void	move_ghost(t_data *data, int x, int y);
void	put_image(t_data *data, char flag, int j, int i);
void	print_counter(t_data *data);

#endif
