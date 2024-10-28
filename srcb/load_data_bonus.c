/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:15:43 by marvin            #+#    #+#             */
/*   Updated: 2024/10/28 18:52:20 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	pacman_animation(t_data *data, t_sprites *img, int w, int h)
{

		img->p1 = mlx_xpm_file_to_image(data->mlx, "img/1.xpm", &w, &h);
		if (!img->p1)
			(printf("Error loading player 1 \n"), (data_destroyer(data)));
		img->p2 = mlx_xpm_file_to_image(data->mlx, "img/2.xpm", &w, &h);
		if (!img->p2)
			(printf("Error loading player 2 \n"), (data_destroyer(data)));
		img->p3 = mlx_xpm_file_to_image(data->mlx, "img/3.xpm", &w, &h);
		if (!img->p3)
			(printf("Error loading player 3 \n"), (data_destroyer(data)));
}

void	loading(t_data *data, t_sprites *img)
{
	int	w;
	int	h;

	w = data->width ;
	h = data->height;
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
	img->e = mlx_xpm_file_to_image(data->mlx, "img/apple.xpm", &w, &h);
	if (!img->e)
		(printf("Error loading exit"), (data_destroyer(data)));
	img->n = mlx_xpm_file_to_image(data->mlx, "img/clyde.xpm", &w, &h);
	if (!img->n)
		(printf("Error loading enemy"), (data_destroyer(data)));
	ft_printf("%d\n", w);
	ft_printf("%d\n", h);
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
			data->img->p2, j , i);
		data->pacman = 2;
	}
	else if (data->pacman == 2)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->p3, j, i);
		data->pacman = 0;
	}
}

static void	put_image(t_data *data, char flag, int j, int i)
{
	j = j * 2;
	i = i * 2;
	if (flag == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->w, j * 16, i * 16);
	else if (flag == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->bg, j * 16, i * 16);
	else if (flag == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->c, j * 16, i * 16);
	else if (flag == 'P')
		put_pacman(data, j * 16, i * 16);
	else if (flag == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->e, j * 16, i * 16);
	else if (flag == 'N')
		mlx_put_image_to_window(data->mlx, data->mlx_window, \
			data->img->n, j * 16, i * 16);
}

void	print_counter(t_data *data)
{
	char	*str;
	char	*num;

	str = ft_strdup("player moves:_ ");
	num = ft_itoa(data->moves);
	str = ft_gnlstrjoin(str, num, ft_strlen(num));
	mlx_string_put(data->mlx, data->mlx_window, (data->width * 70 ), (data->height ) + 10, 0xFFFFFFF, str);
	//mlx_string_put(data->mlx, data->mlx_window, (2 * 100), (data->height + 1) * 5 - 20, 0xFFFFFFF, str);
	free(str);
	if (num)
		free(num);
}

void	drawing(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	//loading(data, data->img);
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
