/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:52:27 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 20:05:19 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
			if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				return (0);
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
	int	n_items;

	if (!is_rectangular(data->map) || !wall_surrounded(data->map))
	{
		ft_printf("Error it's not rectangular or wall surrounded\n");
		data_destroyer(data);
	}
	if (!check_items(data, map))
		(ft_printf("Error checking items\n"), data_destroyer(data));
	if (!check_chars(map))
		return (data_destroyer(data), 0);
	n_items = data->m_map->collect;
	data->width = ft_strlen(map[0]);
	data->height = ft_len(map);
	find_player(data);
	flood_fill(data, data->pos_x, data->pos_y);
	if (!game_conditions(data))
	{
		ft_printf("Error: Unavailable Game Conditions\n");
		data_destroyer(data);
	}
	data->m_map->collect = n_items;
	return (1);
}

int	read_map(t_data *data)
{
	char	*line;
	char	*str_map;

	line = get_next_line(data->fd);
	if (!line || ft_strlen(line) < 3)
		(ft_printf("Empty or invalid size\n"), data_destroyer(data));
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
	if ((!data->map && !data->run_map) || ft_len(data->map) > 20)
		(ft_printf("NULL or Wrong size map\n"), data_destroyer(data));
	if (!check_map(data, data->map) || ft_strlen(data->map[0]) > 40)
		(ft_printf("Error: Cheking Map\n"), data_destroyer(data));
	return (1);
}

int	check(t_data *data, char **argv)
{
	if (argv[1])
		data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
	{
		ft_putstr_fd("Error: Invalid fd\n", 2);
		data_destroyer(data);
	}
	if (!read_map(data))
		return (0);
	return (1);
}
