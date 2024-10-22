/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gongarci <gongarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:05:27 by gongarci          #+#    #+#             */
/*   Updated: 2024/10/22 22:38:19 by gongarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_format(char *file)
{
	int		len;
	char	*ext;

	len = ft_strlen(file);
	if (len < 5 || ft_strncmp(&file[len - 4], ".ber", 4))
		return (0);
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
		return (0);
	if (!check_format(argv[1]) || open(argv[1], O_RDONLY) < 0)
		return (0);
	return (1);
}
