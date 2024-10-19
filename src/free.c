/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:04:42 by marvin            #+#    #+#             */
/*   Updated: 2024/10/07 21:04:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_sprites(t_data *data)
{
	if (data->sprites->collect)
		mlx_destroy_image(data->mlx,data->sprites->collect);
	if (data->sprites->exit)
		mlx_destroy_image(data->mlx, data->sprites->exit);
	if (data->sprites->unlock_exit)
		mlx_destroy_image(data->mlx, data->sprites->unlock_exit);
	if (data->sprites->player)
		mlx_destroy_image(data->mlx, data->sprites->player);
	if (data->sprites->wall)
		mlx_destroy_image(data->mlx, data->sprites->wall);
	if (data->sprites->bg)
		mlx_destroy_image(data->mlx, data->sprites->bg);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

void	free_array(char **array1, char **array2)
{
	while(*array1)
		free(*array1++);
	if (*array1 != NULL)
		free(array1);
	while(*array2)
		free(*array2++);
	if (*array2 != NULL)
		free(array2);
}
int	data_destroyer(t_data *data)
{
	/* if (!data->mlx_window)
		return (free(data->mlx_window), -1); */
	mlx_destroy_window(data->mlx, data->mlx_window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_array(data->map, data->run_map);
	free(data->sprites);
	free_sprites(data);
	free(data->m_map);
	exit (0);
	//return (0); 
}