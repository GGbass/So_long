/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:52:27 by marvin            #+#    #+#             */
/*   Updated: 2024/10/12 19:39:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*  1 = wall
	0 = path
	E = Enemy
	P = player
	C = Collectable */

/* int	valid_map(t_data *data, char **map)

	
} */


int	wall_surrounded(char **map)
{
	char	wall;
	int		i;
	int		j;

	j = 0;
	i = -1;
	wall = '1';
	while(map[++i] != NULL)
	{
		j = 0;
		if (map[i] == 0 || i == ft_len(map))
		{
			while(map[i][j] != '\0')
			{
				//available char ->'1'
				if (map[i][j] != wall ) //|| !available_char(map[i][j++]))
					return (0);
			}
		}
		if (i > 0 && i < ft_len)
		{
			if (map[i][j] == wall && map[i][ft_strlen(map[i])] == wall)
			{
				while(map[i][j] != '\0')
				{
					//available char ->'1'
					if (!available_char(map[i][j++]))  //freed memory
						return (0);
				}
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
	fline = ft_strlen(map[i]);
	while(map[i] != NULL)
	{
		if (fline != ft_strlen(map[i]) || !ft_empty(map[i++]))
		{
			//free map;
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}

int	check_map(t_data *data, char **map)
{
	int	pos_x;
	int	pos_y;
	int	n_items;
	
	if (!is_rectangular(map) || !wall_surrounded(map))
	{
		//free(str array map)
		return (0);
	}
	if (!check_items(data, map))
	{
		return (0);
	}
	data->m_map->width = ft_len(map);
	data->m_map->height = ft_strlem(map[0]);
	n_items = data->m_map->collect;
	x = data->m_map->widht; // amounts of rows on map
	y = data->m_map->y; //  player character position;
	flood_filld(data, pos_x, pos_y);
	data->m_map->collect = n_items;
	return (1);
}

int	read_map(t_data *data)
{
	char	*line;
	char	*str_map;
	//char	**map;

	line = get_next_line(data->fd);
	while(line)
	{
		str_map = ft_gnlstrjoin(str_map, line , ft_strlen(line));
		free(line);
		line = get_next_line(data->fd);
	}
	if (line)
		free(line);
	data->map = ft_split(str_map, '\n');
	if (!data->map)
	{
		return (free_array(data->map), 0);
	}
	if (!check_map(data, data->map))
	{
		//free array str data->map;
		// free data;
		return (free_array(data->map), 0);
	}
	return (1);
}

int	check(t_data *data, int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		ft_put_str_fd("Error\n", 2);
		//free *data
	}
	if (argv[1])
		data->fd = open(argv[1], O_RDONLY);
	if (data->fd < 0)
	{
		//free *data
		return (ft_put_str_fd("Error\n", 2), -1);
	}
	if (!read_map(data))
	{
		return (0);
	}
	return (1);
}
