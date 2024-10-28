/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:35:56 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/28 17:43:30 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	find_ghost(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'N')
			{
				data->ghost_x = i;
				data->ghost_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	ghost_location(t_data *data, int x, int y)
{
	data->ghost_x = x;
	data->ghost_y = y;
}


void	move_ghost(t_data *data, int x, int y)
{
	if (data->run_map[x][y] == '1')
		return ;
	else if (data->run_map[x][y] == 'C')
		return ;
	else if (data->run_map[x][y] == 'E')
		return ;
	else if (data->run_map[x][y] == 'P')
	{
		ft_printf("Ghost win !\n");
		data_destroyer(data);
	}
	else if (data->run_map[x][y] == '0')
	{
		data->run_map[x][y] = 'N';
		data->run_map[data->ghost_x][data->ghost_y] = '0';
		ghost_location(data, x, y);
	}
	drawing(data);
}
