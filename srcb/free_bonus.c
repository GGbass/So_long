/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 21:04:42 by marvin            #+#    #+#             */
/*   Updated: 2024/11/05 19:51:50 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	free_sprites(t_data *data)
{
	if (data->img)
	{
		if (data->img->c)
			mlx_destroy_image(data->mlx, data->img->c);
		if (data->img->e)
			mlx_destroy_image(data->mlx, data->img->e);
		if (data->img->p1)
			mlx_destroy_image(data->mlx, data->img->p1);
		if (data->img->p2)
			mlx_destroy_image(data->mlx, data->img->p2);
		if (data->img->p3)
			mlx_destroy_image(data->mlx, data->img->p3);
		if (data->img->w)
			mlx_destroy_image(data->mlx, data->img->w);
		if (data->img->bg)
			mlx_destroy_image(data->mlx, data->img->bg);
		if (data->img->n)
			mlx_destroy_image(data->mlx, data->img->n);
	}
	return ;
}

void	free_array(char **array1, char **array2)
{
	int	i;

	i = 0;
	if (*array1 != NULL)
	{
		while (array1[i] != NULL)
			free(array1[i++]);
		if (array1)
			free(array1);
		i = 0;
		while (array2[i] != NULL)
			free(array2[i++]);
		if (array2)
			free(array2);
	}
}

int	data_destroyer(t_data *data)
{
	if (data->map || data->run_map)
		free_array(data->run_map, data->map);
	if (data->m_map)
		free(data->m_map);
	if (data->fd)
		close(data->fd);
	free_sprites(data);
	if (data->img)
	{
		if (data->mlx)
		{
			mlx_loop_end(data->mlx);
			mlx_destroy_window(data->mlx, data->mlx_window);
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
		free(data->img);
	}
	if (data)
		free(data);
	exit(0);
}
