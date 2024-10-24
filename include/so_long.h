/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:27:52 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/24 02:08:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

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
	void	*u_e;
	void	*p;
	void	*w;
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
	int			height;
	void		*mlx;
	void		*mlx_window;
	int			fd;
	int			moves;
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

#endif
