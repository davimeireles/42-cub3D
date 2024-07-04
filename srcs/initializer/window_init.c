/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:45:24 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/24 10:45:24 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	window_init(t_cub3d *cub3D)
{
	cub3D->connection = mlx_init();
	if (!cub3D->connection)
	{
		free_memory(cub3D);
		exit(EXIT_FAILURE);
	}
	cub3D->window = mlx_new_window(cub3D->connection, 1280, 720, "cub3d");
	if (!cub3D->window)
	{
		free(cub3D->connection);
		free_memory(cub3D);
		exit(EXIT_FAILURE);
	}
}
