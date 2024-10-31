/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:05:27 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/30 01:49:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_format(char *file)
{
	int		len;
	char	*ext;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(&file[len - 4], ".ber", 4))
	{
		ft_printf("Error: Invalid file format\n");
		return (0);
	}
	ext = ft_strchr(file, '.');
	if (ext == NULL)
		return (0);
	if (ft_strncmp(ext, ".ber", 0))
		return (1);
	return (1);
}

int	check_argv(int argc, char **argv)
{
	if (argc != 2 || !argv[1])
	{
		ft_printf("Error: Invalid arguments\n");
		return (0);
	}
	if (!check_format(argv[1]))
		return (0);
	if (open(argv[1], O_RDONLY) < 0)
	{
		ft_printf("Error: Invalid file\n");
		return (0);
	}
	return (1);
}
