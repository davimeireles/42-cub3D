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

void	free_mlx(t_cub3d *cub3D)
{
	if (cub3D->window)
		mlx_destroy_window(cub3D->connection,cub3D->window);
	if (cub3D->connection)
	{
		mlx_destroy_display(cub3D->connection);
		free(cub3D->connection);
	}
	free_memory(cub3D);
}

int	key_hook(int keycode, t_cub3d *cub3D)
{
	if (keycode == 65307)
	{
		mlx_loop_end(cub3D->connection);
		free_mlx(cub3D);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

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
	mlx_key_hook(cub3D->window, key_hook, cub3D);
	mlx_loop(cub3D->connection);
	mlx_loop_end(cub3D->connection);
}