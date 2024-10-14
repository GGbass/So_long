/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:52:48 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/14 19:20:26 by gongarci         ###   ########.fr       */
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

int	keys_press(int key, t_data *data)
{
	(void)data;
	ft_printf("Key ; %d\n", key);
	return (0);
}
void	game_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_printf("Fail at initialize game\n");
		return (free_array(data->map));
	}
	data->m_map->width = 800;
	data->m_map->height = 600;
	loading(data);
	data->mlx_window = mlx_new_window(data->mlx, 800, 600, "PACMAN SO_LONG");
	if (!data->mlx_window)
		return (free(data->mlx_window));
	mlx_hook(data->mlx_window, DestroyNotify, StructureNotifyMask, &data_destroyer, &data);
	mlx_key_hook(data->mlx, &keys_press, &data);
	mlx_loop(data->mlx);
}
int	main(int argc, char **argv)
{
	t_data *data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
	if (check(data, argc, argv))
	{
		return (0);
	}
	game_init(data);
/* 	loading(data);
	mlx_hook(data->mlx_window, DestroyNotify, StructureNotifyMask, &data_destroyer, &data);
	mlx_key_hook(data->mlx, &keys_press, &data);
	mlx_loop(data->mlx); */
	return (0);
}
