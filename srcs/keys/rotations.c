/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 06:38:53 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/14 06:39:02 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rotate_left(t_cub3d *cub3d)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = cub3d->player->dir_x;
	cub3d->player->dir_x = cub3d->player->dir_x * cos(cub3d->player->rotation) - cub3d->player->dir_y * sin(cub3d->player->rotation);
	cub3d->player->dir_y = oldDirX * sin(cub3d->player->rotation) + cub3d->player->dir_y * cos(cub3d->player->rotation);
	oldPlaneX = cub3d->player->plane_x;
	cub3d->player->plane_x = cub3d->player->plane_x * cos(cub3d->player->rotation) - cub3d->player->plane_y * sin(cub3d->player->rotation);
	cub3d->player->plane_y = oldPlaneX * sin(cub3d->player->rotation) + cub3d->player->plane_y * cos(cub3d->player->rotation);
	return (-1);
}

int rotate_right(t_cub3d *cub3d)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = cub3d->player->dir_x;
	cub3d->player->dir_x = cub3d->player->dir_x * cos(-cub3d->player->rotation) - cub3d->player->dir_y * sin(-cub3d->player->rotation);
	cub3d->player->dir_y = oldDirX * sin(-cub3d->player->rotation) + cub3d->player->dir_y * cos(-cub3d->player->rotation);
	oldPlaneX = cub3d->player->plane_x;
	cub3d->player->plane_x = cub3d->player->plane_x * cos(-cub3d->player->rotation) - cub3d->player->plane_y * sin(-cub3d->player->rotation);
	cub3d->player->plane_y = oldPlaneX * sin(-cub3d->player->rotation) + cub3d->player->plane_y * cos(-cub3d->player->rotation);
	return (1);
}
