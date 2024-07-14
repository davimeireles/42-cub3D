/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 06:38:53 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/14 19:35:28 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_left(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->player->dir_x;
	cub3d->player->dir_x = cub3d->player->dir_x
		* cos(cub3d->player->rotation) - cub3d->player->dir_y
		* sin(cub3d->player->rotation);
	cub3d->player->dir_y = old_dir_x * sin(cub3d->player->rotation)
		+ cub3d->player->dir_y
		* cos(cub3d->player->rotation);
	old_plane_x = cub3d->player->plane_x;
	cub3d->player->plane_x = cub3d->player->plane_x
		* cos(cub3d->player->rotation) - cub3d->player->plane_y
		* sin(cub3d->player->rotation);
	cub3d->player->plane_y = old_plane_x * sin(cub3d->player->rotation)
		+ cub3d->player->plane_y * cos(cub3d->player->rotation);
	return (-1);
}

int	rotate_right(t_cub3d *cub3d)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub3d->player->dir_x;
	cub3d->player->dir_x = cub3d->player->dir_x * cos(-cub3d->player->rotation)
		- cub3d->player->dir_y * sin(-cub3d->player->rotation);
	cub3d->player->dir_y = old_dir_x * sin(-cub3d->player->rotation)
		+ cub3d->player->dir_y * cos(-cub3d->player->rotation);
	old_plane_x = cub3d->player->plane_x;
	cub3d->player->plane_x = cub3d->player->plane_x
		* cos(-cub3d->player->rotation) - cub3d->player->plane_y
		* sin(-cub3d->player->rotation);
	cub3d->player->plane_y = old_plane_x * sin(-cub3d->player->rotation)
		+ cub3d->player->plane_y * cos(-cub3d->player->rotation);
	return (1);
}
