/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:27:52 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/12 19:01:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_sprites
{
	void	*collect;
	void	*exit;
	void	*unlock_exit;
	void	*player;
	void	*wall;
	void	*bg;
}			t_sprites;

typedef struct s_data
{
	void		*mlx;
	void		*mlx_window;
	int			fd;
	char		**mapa;
	t_sprites	*sprites;
	t_map		*m_map;
}			t_data;

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

int		available_char(char c);
void	loading(t_data *data);
void	check(t_data *data, int argc, char **argv);
void	free_array(char **str);

#endif
