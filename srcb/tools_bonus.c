/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:19:54 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/29 21:56:52 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] != '\0')
		{
			if (data->map[i][j] == 'P')
			{
				data->pos_x = i;
				data->pos_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	game_conditions(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_strchr(data->map[i], 'E') || ft_strchr(data->map[i], 'C'))
			return (0);
		i++;
	}
	return (1);
}

int	available_char(char c)
{
	char	*available;

	available = "01PECN";
	if (ft_strchr(available, c) == NULL)
		return (ft_printf("Invalid char \n"), 0);
	return (1);
}

int	check_items(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	data->m_map = ft_calloc(1, sizeof(t_map));
	if (data->m_map == NULL)
		return (0);
	while (map[++i])
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] == 'C')
				data->m_map->collect++;
			else if (map[i][j] == 'E')
				data->m_map->exit++;
			else if (map[i][j] == 'P')
				data->m_map->player++;
		}
	}
	if (data->m_map->player == 1 && data->m_map->collect >= 1
		&& data->m_map->exit == 1)
		return (1);
	return (0);
}

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->width
		|| data->map[x][y] == '1'
		|| data->map[x][y] == 'X'
		|| data->map[x][y] == 'N')
		return ;
	if (data->map[x][y] == 'C')
		data->m_map->collect--;
	if (data->map[x][y] == 'E' && data->m_map->collect != 0)
		return ;
	data->map[x][y] = 'X';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}
