/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:15:43 by marvin            #+#    #+#             */
/*   Updated: 2024/10/05 18:15:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	loading(t_data *data, t_sprites *img)
{
	int	w;
	int	h;

	img->w = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &w, &h);
	img->bg = mlx_xpm_file_to_image(data->mlx, "img/black.xpm",&w, &h);
	img->c = mlx_xpm_file_to_image(data->mlx, "img/dot.xpm", &w, &h);
	img->p = mlx_xpm_file_to_image(data->mlx, "img/2.xpm", &w, &h);
	img->e = mlx_xpm_file_to_image(data->mlx, "img/apple.xpm", &w, &h);
}

void	drawing(t_data *data, t_sprites *img)
{
	int	i;
	int	j;

	i = 0;
	while(data->run_map[i])
	{
		j = 0;
		while(data->run_map[i][j])
		{
			if (data->run_map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_window, img->w, j * 40, i * 50);
			else if (data->run_map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_window, img->bg, j * 40, i * 50);
			else if (data->run_map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_window, img->c, j * 40, i * 50);
			else if (data->run_map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_window, img->p, j * 40, i * 50);
			else if (data->run_map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_window, img->e, j * 40, i * 50);
			j++;
		}
		i++;
	}
}
