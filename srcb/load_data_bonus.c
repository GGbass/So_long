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

#include "../include/so_long_bonus.h"

void	pacman_animation(t_data *data, t_sprites *img, int w, int h)
{
	if (img->p != NULL)
	{
		mlx_destroy_image(data->mlx, img->p);
		//free(img->p);
		img->p = ft_calloc(1, sizeof(void *));
	}	
	if (data->pacman == 0)
	{
		img->p = mlx_xpm_file_to_image(data->mlx, "img/1.xpm", &w, &h);
		data->pacman = 1;
	}
	else if (data->pacman == 1)
	{
		img->p = mlx_xpm_file_to_image(data->mlx, "img/2.xpm", &w, &h);
		data->pacman = 2;
	}
	else
	{
		img->p = mlx_xpm_file_to_image(data->mlx, "img/3.xpm", &w, &h);
		data->pacman = 0;
	}
}

void	loading(t_data *data, t_sprites *img)
{
	int	w;
	int	h;
 
	img->w = mlx_xpm_file_to_image(data->mlx, "img/wall.xpm", &w, &h);
	if (!img->w)
		(printf("Error loading walls"), (data_destroyer(data)));
	img->bg = mlx_xpm_file_to_image(data->mlx, "img/black.xpm", &w, &h);
	if (!img->bg)
		(printf("Error loading background"), (data_destroyer(data)));
	img->c = mlx_xpm_file_to_image(data->mlx, "img/dot.xpm", &w, &h);
	if (!img->c)
		(printf("Error loading collectibles"), (data_destroyer(data)));
	pacman_animation(data, img, w, h);
	//img->p = mlx_xpm_file_to_image(data->mlx, "img/1.xpm", &w, &h);
	if (!img->p)
		(printf("Error loading player"), (data_destroyer(data)));
	img->e = mlx_xpm_file_to_image(data->mlx, "img/apple.xpm", &w, &h);
	if (!img->e)
		(printf("Error loading exit"), (data_destroyer(data)));
	img->n = mlx_xpm_file_to_image(data->mlx, "img/clyde.xpm", &w, &h);
	if (!img->n)
		(printf("Error loading enemy"), (data_destroyer(data)));
}

static void	put_image(t_data *data, char flag, int j, int i)
{
	if (flag == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->w, j * 40, i * 50);
	else if (flag == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->bg, j * 40, i * 50);
	else if (flag == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->c, j * 40, i * 50);
	else if (flag == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->p, j * 40, i * 50);
	else if (flag == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->e, j * 40, i * 50);
	else if (flag == 'N')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->n, j * 40, i * 50);
}

void	print_counter(t_data *data)
{
	char	*str;
	char	*num;

	str = ft_strdup("player moves   : ");
	num = ft_itoa(data->moves);
	str = ft_gnlstrjoin(str, num, ft_strlen(num));
	mlx_string_put(data->mlx, data->mlx_window, (data->width * 70 ), (data->height ) + 10, 0xFFFFFFF, str);
	free(str);
	if (num)
		free(num);
}

void	drawing(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	loading(data, data->img);
	while (data->run_map[i])
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
		i++;
	}
	print_counter(data);
}
