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
	if (data->img)
	{
		if (data->img->c)
			mlx_destroy_image(data->mlx, data->img->c);
		if (data->img->e)
			mlx_destroy_image(data->mlx, data->img->e);
		if (data->img->p)
			mlx_destroy_image(data->mlx, data->img->p);
		if (data->img->w)
			mlx_destroy_image(data->mlx, data->img->w);
		if (data->img->bg)
			mlx_destroy_image(data->mlx, data->img->bg);
	}
}

void	free_array(char **array1, char **array2)
{
	if (*array1 != NULL)
	{
		while (*array1)
			free(*array1++);
		if (*array1)
			free(array1);
		while (*array2)
			free(*array2++);
		if (*array2)
			free(array2);
	}
}

int	data_destroyer(t_data *data)
{
	free_sprites(data);
	if (data->img)
	{
		if (data->mlx_window)
			mlx_destroy_window(data->mlx, data->mlx_window);
		if (data->mlx)
		{
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		free(data->img);
	}
	if (data->map && data->run_map)
		free_array(data->map, data->run_map);
	if (data->m_map)
		free(data->m_map);
	if (data->fd)
		close(data->fd);
	exit (0);
}
