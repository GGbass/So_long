/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:52:27 by marvin            #+#    #+#             */
/*   Updated: 2024/10/22 00:21:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	wall_surrounded(char **map)
{
	int		i;
	int		j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = 0;
		if (i == 0 || i == (ft_len(map) - 1))
		{
			while (map[i][j] != '\0')
			{
				if (map[i][j++] != '1')
					return (0);
			}
		}
		if (i > 0 && i < ft_len(map))
		{
			while (map[i][j] != '\0' && map[i][j] != '1')
			{
				if (!available_char(map[i][j++]))
					return (0);
			}
		}
	}
	return (1);
}

int	is_rectangular(char **map)
{
	int	i;
	int	fline;

	i = 0;
	fline = ft_strlen(map[0]);
	while (map[i] != NULL)
	{
		if (fline != ft_strlen(map[i]) || ft_empty(map[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_map(t_data *data, char **map)
{
	int	x;
	int	y;
	int	n_items;

	if (!is_rectangular(data->map) || !wall_surrounded(data->map))
	{
		return (data_destroyer(data), 0);
		//return (free_array(data->map, data->run_map), 0);
	}
	if (!check_items(data, map))
	{
		return (data_destroyer(data), 0);
		//return (free_array(data->map, data->run_map), 0);
	}
	n_items = data->m_map->collect;
	data->m_map->width = ft_len(map);
	data->m_map->height = ft_strlen(map[0]);
	x = data->m_map->width;
	y = data->m_map->y;
	flood_fill(data, x, y);
	data->m_map->collect = n_items;
	return (1);
}

int	read_map(t_data *data)
{
	char	*line;
	char	*str_map;

	line = get_next_line(data->fd);
	str_map = ft_strdup("");
	while (line)
	{
		str_map = ft_gnlstrjoin(str_map, line, ft_strlen(line));
		free(line);
		line = get_next_line(data->fd);
	}
	if (line)
		free(line);
	data->map = ft_split(str_map, '\n');
	data->run_map = ft_split(str_map, '\n');
	free(str_map);
	if ((!data->map && !data->run_map) || ft_len(data->map) > 32)
		return (free_array(data->map, data->run_map), 0);
	if (!check_map(data, data->map) || ft_strlen(data->map[0]) > 80)
	{
		ft_printf("Error\n");
		data_destroyer(data);
		//return (free_array(data->map, data->run_map), 0);
	}
	return (1);
}

int	check(t_data *data, int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		data_destroyer(data);
		return (ft_putstr_fd("Error\n", 2), 0);
	}
	if (argv[1])
		data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
	{
		return (ft_putstr_fd("Error\n", 2), 0);
	}
	if (!read_map(data))
	{
		return (0);
	}
	return (1);
}
