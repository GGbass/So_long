/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 18:16:00 by y marvin          #+#    #+#             */
/*   Updated: 2024/10/29 00:40:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	pacman_animation(t_data *data, t_sprites *img, int w, int h)
{
	img->p1 = mlx_xpm_file_to_image(data->mlx, "img/111.xpm", &w, &h);
	if (!img->p1)
		(printf("Error loading player 1 \n"), (data_destroyer(data)));
	img->p2 = mlx_xpm_file_to_image(data->mlx, "img/222.xpm", &w, &h);
	if (!img->p2)
		(printf("Error loading player 2 \n"), (data_destroyer(data)));
	img->p3 = mlx_xpm_file_to_image(data->mlx, "img/333.xpm", &w, &h);
	if (!img->p3)
		(printf("Error loading player 3 \n"), (data_destroyer(data)));
}

void	loading(t_data *data, t_sprites *img)
{
	int	w;
	int	h;

	w = data->width;
	h = data->height;
	img->w = mlx_xpm_file_to_image(data->mlx, "img/wall22.xpm", &w, &h);
	if (!img->w)
		(printf("Error loading walls"), (data_destroyer(data)));
	img->bg = mlx_xpm_file_to_image(data->mlx, "img/black22.xpm", &w, &h);
	if (!img->bg)
		(printf("Error loading background"), (data_destroyer(data)));
	img->c = mlx_xpm_file_to_image(data->mlx, "img/dot22.xpm", &w, &h);
	if (!img->c)
		(printf("Error loading collectibles"), (data_destroyer(data)));
	pacman_animation(data, img, w, h);
	img->e = mlx_xpm_file_to_image(data->mlx, "img/apple22.xpm", &w, &h);
	if (!img->e)
		(printf("Error loading exit"), (data_destroyer(data)));
	img->n = mlx_xpm_file_to_image(data->mlx, "img/clyde22.xpm", &w, &h);
	if (!img->n)
		(printf("Error loading enemy"), (data_destroyer(data)));
}

void	put_pacman(t_data *data, int j, int i)
{
	if (data->pacman == 0)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->p1, j, i);
		data->pacman = 1;
	}
	else if (data->pacman == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->p2, j, i);
		data->pacman = 2;
	}
	else if (data->pacman == 2)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->p3, j, i);
		data->pacman = 0;
	}
}

void	put_image(t_data *data, char flag, int j, int i)
{
	if (flag == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->w, j * 64, i * 64);
	else if (flag == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->bg, j * 64, i * 64);
	else if (flag == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->c, j * 64, i * 64);
	else if (flag == 'P')
		put_pacman(data, j * 64, i * 64);
	else if (flag == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->e, j * 64, i * 64);
	else if (flag == 'N')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->n, j * 64, i * 64);
}

void	drawing(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->run_map[++i])
	{
		j = 0;
		while (data->run_map[i][j])
		{
			if (data->run_map[i][j] == '1')
				put_image(data, '1', j, i);
			else if (data->run_map[i][j] == '0')
				put_image(data, '0', j, i);
			else if (data->run_map[i][j] == 'C')
				put_image(data, 'C', j, i);
			else if (data->run_map[i][j] == 'P')
				put_image(data, 'P', j, i);
			else if (data->run_map[i][j] == 'E')
				put_image(data, 'E', j, i);
			else if (data->run_map[i][j] == 'N')
				put_image(data, 'N', j, i);
			j++;
		}
	}
	print_counter(data);
}
