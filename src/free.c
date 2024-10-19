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

/* void	free_sprites(t_data *data)
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
} */

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
