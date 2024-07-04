/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:42:09 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/01 17:47:52 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	esc_hook(int keycode, t_cub3d *cub3D)
{
	if (keycode == 65307)
	{
		mlx_loop_end(cub3D->connection);
		free_mlx(cub3D);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	close_window_x(t_cub3d *cub3D)
{
	mlx_loop_end(cub3D->connection);
	free_mlx(cub3D);
	exit(EXIT_SUCCESS);
	return (0);
}