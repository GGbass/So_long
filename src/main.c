/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:52:48 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/18 19:25:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	data_destroyer(t_data *data)
{
	if (!data->mlx_window)
		return (free(data->mlx_window), -1);
	mlx_destroy_window(data->mlx, data->mlx_window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
	//return (0);
}
void	move(t_data *data, int x, int y)
{
	/* if (data->run_map[data->m_map->x + x][data->m_map->y + y] == 'E')
	{
		data_destroyer(data);
	} */
	if (data->run_map[x][y] == 'C')
	{
		data->run_map[x][y] = 'P';
		data->m_map->collect--;
	}
	if (data->run_map[x][y] == 'E')
	{
		data_destroyer(data);
		return ;
	}
	drawing(data);
	ft_printf("Player moves %d\n", data->moves++);
}


int	keys_press(int key, t_data *data)
{
	ft_printf("Key ; %d\n", key);
	if (key == UP_W || key == UP_ARROW)
	{
		move(data, data->m_map->x - 1, data->m_map->y);
		ft_printf("UP\n");
	}
	else if (key == DOWN_S || key == DOWN_ARROW)
	{
		move(data, data->m_map->x + 1, data->m_map->y);
		ft_printf("DOWN\n");
	}
	else if (key == LEFT_A || key == LEFT_ARROW)
	{
		move(data, data->m_map->x, data->m_map->y - 1);
		ft_printf("LEFT\n");
	}
	else if (key == RIGHT_D || key == RIGHT_ARROW)
	{
		move(data, data->m_map->x, data->m_map->y + 1);
		ft_printf("RIGHT\n");
	}
	else if (key == ESC)
	{
		data_destroyer(data);
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
	data->m_map->width = (ft_strlen(data->run_map[0]) - 1) * 20;
	data->m_map->height = ft_len(data->run_map) * 25;
	data->mlx_window = mlx_new_window(data->mlx, data->m_map->width, data->m_map->height, "PACMAN SO_LONG");
	if (!data->mlx_window)
		return (free(data->mlx_window));
	loading(data);
	drawing(data);
	mlx_hook(data->mlx_window, DestroyNotify, StructureNotifyMask, &data_destroyer, &data);
	mlx_hook(data->mlx_window, 2, 1L << 0, keys_press, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data *data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
	if (!check(data, argc, argv))
	{
		return (free_array(data->map, data->run_map), 0);
		//return (0);
	}
	ft_printf("Map checked\n");
	game_init(data);
	return (0);
}
