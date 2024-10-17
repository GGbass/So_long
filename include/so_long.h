/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:27:52 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/17 23:17:39 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

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
	void	*collect;
	void	*exit;
	void	*unlock_exit;
	void	*player;
	void	*wall;
	void	*bg;
}			t_sprites;


typedef struct s_map
{
	int		width;
	int		height;
	int		x;
	int		y;
	int		collect;
	int		exit;
	int		player;
}			t_map;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_window;
	int			fd;
	char		**map;
	char		**run_map;
	t_sprites	*sprites;
	t_map		*m_map;
}			t_data;

int		available_char(char c);
void	loading(t_data *data);
int		check(t_data *data, int argc, char **argv);
void	free_array(char **array1, char **array2);
int		check_items(t_data *data, char **map);
void	flood_fill(t_data *data, int x, int y);
void	drawing(t_data *data);

#endif
