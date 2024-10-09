/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:52:27 by marvin            #+#    #+#             */
/*   Updated: 2024/10/05 18:52:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_rectangular(char **map)
{
	int	i;
	int	fline;

	i = 0;
	fline = ft_strlen(map[i]);
	while(map[i] != NULL)
	{
		if (fline != ft_strlen(map[i++]))
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}

void	check_map(t_data *data, int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		ft_put_str_fd("Error\n", 2);
	}
}

void	flood_fill()
{

}