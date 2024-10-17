/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:19:54 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/17 19:41:33 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	game_conditions(t_data *data)
{
	if (data->m_map->player == 1 && data->m_map->collect >= 1 && data->m_map->exit == 1)
		return (1);
	return (0);
	//check for enemies ?
}

int	available_char(char c)
{
	char	*available;

	available = "01PEC";
	if (ft_strchr(available, c) == NULL)
		return (0);
	return (1);
}

int	check_items(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j] != '\0')
		{
			if (!available_char(map[i][j]) && (map[i][j++] != '\0'))
				return (0);
			else if (map[i][j++] == 'C')
				data->m_map->collect++;
			else if (map[i][j++] == 'E')
				data->m_map->exit++;
			else if (map[i][j++] == 'P')
			{
				data->m_map->player++;
				data->m_map->x = i;
				data->m_map->y = ft_strchr(data->map[i], 'P') - data->map[i];
			}
		}
		i++;
	}
	return (1);
}

void	flood_fill(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->m_map->width
		|| data->map[x][y] == '1'
		|| data->map[x][y] == 'X')
		return ;
	if (data->map[x][y] == 'C')
		data->m_map->collect--;
	if (data->map[x][y] == 'E' && data->m_map->collect != 0)
		return ;
	if (!available_char(data->map[x][y]))
		return ;
	data->map[x][y] = 'X';
	flood_fill(data, x + 1, y);
	flood_fill(data, x - 1, y);
	flood_fill(data, x, y + 1);
	flood_fill(data, x, y - 1);
}


/* int	pass_condition(char )
{
	
void	start_game(t_map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		ft_putstr_fd(RED "Error! " RC, 2);
		ft_putstr_fd("No se pudo iniciar el mlx\n", 2);
		return ;
	}
	if (map->size.width <= 40 && map->size.height <= 100)
		map->win = mlx_new_window(map->mlx, map->size.height * SIZE, \
			map->size.width * SIZE, "La leyenda de Sombra");
	if (!map->win)
	{
		ft_putstr_fd(RED "Error! " RC, 2);
		ft_putstr_fd("No se pudo iniciar la ventana\n", 2);
		free_map(map);
		print_error(2);
	}
	
} */