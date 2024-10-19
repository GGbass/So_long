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

void	loading(t_data *data)
{
	int	widt;
	int	height;
	data->sprites = ft_calloc(1, sizeof(t_sprites));
	if (!data->sprites)
	{
		ft_printf("fail data->sprites\n");
		return ;
	}
	data->sprites->wall = mlx_xpm_file_to_image(data->mlx, "textures/wall/wall.xpm", &widt, &height);
	data->sprites->bg = mlx_xpm_file_to_image(data->mlx, "textures/wall/black.xpm",&widt, &height);
	data->sprites->collect = mlx_xpm_file_to_image(data->mlx, "textures/pacman-art/other/dot.xpm", &widt, &height);
	data->sprites->player = mlx_xpm_file_to_image(data->mlx, "textures/pacman-art/pacman-right/pac_open_right.xpm", &widt, &height);
	data->sprites->exit = mlx_xpm_file_to_image(data->mlx, "textures/wall/apple.xpm", &widt, &height);
}
void	drawing(t_data *data)
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
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->sprites->wall, j * 40, i * 50);
			else if (data->run_map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->sprites->bg, j * 40, i * 50);
			else if (data->run_map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->sprites->collect, j * 40, i * 50);
			else if (data->run_map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->sprites->player, j * 40, i * 50);
			else if (data->run_map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->sprites->exit, j * 40, i * 50);
			j++;
		}
		i++;
	}
}
