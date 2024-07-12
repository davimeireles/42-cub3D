/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:55:14 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/12 15:16:26 by dmeirele         ###   ########.fr       */
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
	free_memory(cub3d);
	exit(EXIT_FAILURE);
}
