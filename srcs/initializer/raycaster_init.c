/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:42:37 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/14 20:17:30 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	raycaster_init(t_cub3d *cub3d)
{
	cub3d->raycaster->ray.dir[X] = cub3d->player->dir_x;
	cub3d->raycaster->ray.dir[Y] = cub3d->player->dir_y;
	cub3d->raycaster->ray.pos[X] = cub3d->player->x;
	cub3d->raycaster->ray.pos[Y] = cub3d->player->y;
	cub3d->raycaster->ray.plane[X] = cub3d->player->plane_x;
	cub3d->raycaster->ray.plane[Y] = cub3d->player->plane_y;
}
