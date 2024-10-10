/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 21:19:54 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/10 21:52:41 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	available_char(char c)
{
	char	*available;
	
	available = "01PEC";
	if (ft_strchr(available, c) == NULL)
		return (1);
	return (0);
}

/* void	flood_fill()
{

} */

/* int	pass_condition(char )
{
	
} */