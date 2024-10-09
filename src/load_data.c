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
	int	we;
	data->sprites = ft_calloc(1, sizeof(t_sprites));
	if (!data->sprites)
	{
		ft_printf("fail data->sprites\n");
		return ;
	}
	data->sprites->wall = mlx_xpm_file_to_image(data->mlx, "../textures/wall/wall.xpm", &widt, &we);
	data->sprites->bg = mlx_xpm_file_to_image(data->mlx, "../textures/wall/black.xpm",&widt, &we);
	data->sprites->collect = mlx_xpm_file_to_image(data->mlx, "../textures/other/dot.xpm", &widt, &we);
	data->sprites->player = mlx_xpm_file_to_image(data->mlx, "../textures/pacman-art/pacman-right/pac-open-right.xpm",&widt, &we);
}
