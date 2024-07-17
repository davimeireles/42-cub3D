/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:55:14 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/17 21:30:05 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_error(t_error type, t_cub3d *cub3d)
{
	if (type == N_ARGS)
		ft_putendl_fd("Error\nInvalid number of arguments.", 2);
	else if (type == MAP_NAME)
		ft_putendl_fd("Error\nInvalid file name.", 2);
	else if (type == OPEN_ERROR)
		ft_putendl_fd("Error\nError trying to open the file.", 2);
	else if (type == CONFIGS)
		ft_putendl_fd("Error\nMissing/Wrong configuration in the file.", 2);
	else if (type == MEMORY)
		ft_putendl_fd("Error\nBad alloc error.", 2);
	else if (type == INVALID_MAP)
		ft_putendl_fd("Error\nInvalid map.", 2);
	else if (type == RGB)
		ft_putendl_fd("Error\nWrong RGB config.", 2);
	else if (type == TEXTURES)
		ft_putendl_fd("Error\nTexture not found.", 2);
	free_cub3d(cub3d);
	exit(EXIT_FAILURE);
}

void	free_row(t_cub3d *cub3d, int row, char **map)
{
	free(map[row - 1]);
	map[row - 1] = NULL;
	cub3d->map->rows--;
}
