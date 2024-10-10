/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:27:52 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/10 21:57:44 by gongarci         ###   ########.fr       */
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
	char		**map;
	t_sprites	*sprites;
}			t_data;

int		available_char(char c);
void	loading(t_data *data);
void	check(t_data *data, int argc, char **argv);

#endif
