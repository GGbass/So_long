/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:26:38 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/21 17:10:41 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	update_location(t_data *data, int x, int y)
{
	data->pos_x = x;
	data->pos_y = y;
	data->moves++;
}

void	check_exit(t_data *data)
{
	ft_printf("items remining %d\n", data->m_map->collect);
	if (data->m_map->collect == 0)
	{
		ft_printf("moves %d\n", data->moves);
		ft_printf("You win\n");
		data_destroyer(data);
	}
	return ;
}
