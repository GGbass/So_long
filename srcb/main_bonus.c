/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 18:52:48 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/29 23:01:49 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	print_counter(t_data *data)
{
	char	*str;
	char	*num;
	int		x;
	int		y;

	x = data->width - (data->width / 2);
	y = data->height - 200;
	str = ft_strdup("player moves:  ");
	num = ft_itoa(data->moves);
	str = ft_gnlstrjoin(str, num, ft_strlen(num));
	mlx_string_put(data->mlx, data->mlx_window, (x), (y), 0xFFFFFF, str);
	free(str);
	if (num)
		free(num);
}

void	move(t_data *data, int x, int y)
{
	if (data->run_map[x][y] == '1')
		return ;
	else if (data->run_map[x][y] == 'N')
	{
		ft_printf("You lose\n");
		data_destroyer(data);
	}
	else if (data->run_map[x][y] == 'C')
		check_collect(data, x, y);
	else if (data->run_map[x][y] == 'E' || data->run_map[x][y] == 'N')
		check_exit(data, x, y);
	else if (data->run_map[x][y] == '0')
	{
		data->run_map[x][y] = 'P';
		if (data->exit_flag == 1)
		{
			data->run_map[data->pos_x][data->pos_y] = 'E';
			data->exit_flag = 0;
		}
		else
			data->run_map[data->pos_x][data->pos_y] = '0';
		update_location(data, x, y);
	}
	drawing(data);
	ft_printf("Player moves %d\n", data->moves);
}

int	keys_press(int key, t_data *data)
{
	if (key == UP_W)
		move(data, data->pos_x - 1, data->pos_y);
	else if (key == DOWN_S)
		move(data, data->pos_x + 1, data->pos_y);
	else if (key == LEFT_A)
		move(data, data->pos_x, data->pos_y - 1);
	else if (key == RIGHT_D)
		move(data, data->pos_x, data->pos_y + 1);
	else if (key == UP_ARROW && data->n_flag == 1)
		move_ghost(data, data->ghost_x - 1, data->ghost_y);
	else if (key == DOWN_ARROW && data->n_flag == 1)
		move_ghost(data, data->ghost_x + 1, data->ghost_y);
	else if (key == LEFT_ARROW && data->n_flag == 1)
		move_ghost(data, data->ghost_x, data->ghost_y - 1);
	else if (key == RIGHT_ARROW && data->n_flag == 1)
		move_ghost(data, data->ghost_x, data->ghost_y + 1);
	else if (key == ESC)
		(ft_printf("closing game \n"), data_destroyer(data));
	return (1);
}

void	game_init(t_data *data)
{
	int	x;
	int	y;

	data->mlx = mlx_init();
	if (!data->mlx)
		data_destroyer(data);
	data->width = data->width * 64;
	data->height = data->height * 64;
	x = data->height + 25;
	y = data->width;
	data->mlx_window = mlx_new_window(data->mlx, y, x, "PACMAN");
	if (!data->mlx_window)
		data_destroyer(data);
	data->img = ft_calloc(1, sizeof(t_sprites));
	if (!data->img)
		data_destroyer(data);
	data->pacman = 2;
	loading(data, data->img);
	drawing(data);
	(find_player(data), find_ghost(data));
	mlx_hook(data->mlx_window, X, 0, data_destroyer, data);
	mlx_hook(data->mlx_window, 2, 1L << 0, keys_press, data);
	mlx_loop_hook(data->mlx, update, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!check_argv(argc, argv))
		return (ft_printf("Error\n"), 0);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (0);
	if (!check(data, argc, argv))
		return (0);
	game_init(data);
	return (0);
}
