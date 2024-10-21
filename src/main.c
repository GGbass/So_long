/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:52:48 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/21 20:37:48 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move(t_data *data, int x, int y)
{
	if (data->run_map[x][y] == '1')
		return ;
	else if (data->run_map[x][y] == 'C')
	{
		data->run_map[x][y] = 'P';
		data->run_map[data->pos_x][data->pos_y] = '0';
		data->m_map->collect--;
		update_location(data, x, y);
	}
	else if (data->run_map[x][y] == 'E')
	{
		check_exit(data);
	}
	else if(data->run_map[x][y] == '0')
	{
		data->run_map[x][y] = 'P';
		data->run_map[data->pos_x][data->pos_y] = '0';
		update_location(data, x, y);
	}
	drawing(data, data->img);
	ft_printf("Player moves %d\n", data->moves);
}

int	keys_press(int key, t_data *data)
{
	if (key == UP_W || key == UP_ARROW)
	{
		move(data, data->pos_x - 1, data->pos_y);
	}
	else if (key == DOWN_S || key == DOWN_ARROW)
	{
		move(data, data->pos_x + 1, data->pos_y);
	}
	else if (key == LEFT_A || key == LEFT_ARROW)
	{
		move(data, data->pos_x, data->pos_y - 1);
	}
	else if (key == RIGHT_D || key == RIGHT_ARROW)
	{
		move(data, data->pos_x, data->pos_y + 1);
	}
	else if (key == ESC || key == 17 || key == 24)
	{	
		ft_printf(" \n");
		(ft_printf("closing game \n"), data_destroyer(data));
	}
	return (0);
}

void	game_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Fail at initialize game\n");
		return (free_array(data->map, data->run_map));
	}
	data->m_map->width = (ft_strlen(data->run_map[0])) * 40;
	data->m_map->height = ft_len(data->run_map) * 50;
	data->mlx_window = mlx_new_window(data->mlx, data->m_map->width, data->m_map->height, "PACMAN");
	if (!data->mlx_window)
		return (free(data->mlx_window));
	data->img = ft_calloc(1, sizeof(t_sprites));
	if (!data->img)
	{
		ft_printf("fail data->img\n");
		data_destroyer(data);
		return ;
	}
	loading(data, data->img);
	drawing(data, data->img);
	find_player(data);
	mlx_hook(data->mlx_window, DestroyNotify, StructureNotifyMask, data_destroyer, &data);
	mlx_hook(data->mlx_window, 2, 1L << 0, keys_press, data);
	mlx_hook(data->mlx_window, X, 0, data_destroyer, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data *data;

	if (!check_argv(argc, argv))
		return (ft_printf("Error\n"), 0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
	if (!check(data, argc, argv))
	{
		return (0);
		//return (data_destroyer(data)), 0;
	}
	game_init(data);
	return (0);
}
