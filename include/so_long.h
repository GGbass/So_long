/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:27:52 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/07 21:10:36 by marvin           ###   ########.fr       */
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
	t_sprites	*sprites;
}			t_data;

void	loading(t_data *data);


#endif
