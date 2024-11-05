/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:26:38 by gongarci          #+#    #+#             */
/*   Updated: 2024/11/05 19:17:35 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (!available_char(map[i][j]))
			{
				ft_printf("Error: %c Invalid character in map\n", map[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	update_location(t_data *data, int x, int y)
{
	data->pos_x = x;
	data->pos_y = y;
	data->moves++;
}

void	check_exit(t_data *data, int x, int y)
{
	ft_printf("items remining %d\n", data->m_map->collect);
	if (data->m_map->collect == 0)
	{
		ft_printf("moves %d\n", data->moves);
		ft_printf("You win\n");
		data_destroyer(data);
	}
	else if (data->m_map->collect > 0)
	{
		ft_printf("You need to collect all items\n");
		data->run_map[x][y] = 'P';
		data->run_map[data->pos_x][data->pos_y] = '0';
		data->exit_flag = 1;
		update_location(data, x, y);
	}
	return ;
}

void	check_collect(t_data *data, int x, int y)
{
	data->run_map[x][y] = 'P';
	if (data->exit_flag == 1)
	{
		data->run_map[data->pos_x][data->pos_y] = 'E';
		data->exit_flag = 0;
	}
	else
		data->run_map[data->pos_x][data->pos_y] = '0';
	data->m_map->collect--;
	ft_printf("items remining %d\n", data->m_map->collect);
	update_location(data, x, y);
}
