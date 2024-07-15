/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:48:58 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/15 17:49:46 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_x(t_cub3d *cub3d, int dimension)
{
	cub3d->raycaster->ray.wall_x = cub3d->raycaster->ray.pos[dimension]
		+ cub3d->raycaster->ray.perp_wall_distance
		* cub3d->raycaster->ray.ray_dir[dimension];
	cub3d->raycaster->ray.wall_x -= floor(cub3d->raycaster->ray.wall_x);
}

t_img	*vertical_line(t_cub3d *cub3d)
{
	t_img	*texture;

	if (cub3d->raycaster->ray.side == 1)
	{
		if (cub3d->raycaster->ray.ray_dir[Y] <= 0)
			texture = cub3d->screen->south;
		else
			texture = cub3d->screen->north;
	}
	else
	{
		if (cub3d->raycaster->ray.ray_dir[X] > 0)
			texture = cub3d->screen->east;
		else
			texture = cub3d->screen->west;
	}
	return (texture);
}

void	calculate_distance(t_ray *ray, int i)
{
	ray->tile[i] = (int) ray->pos[i];
	if (ray->ray_dir[i] < 0)
	{
		ray->step[i] = -1;
		ray->side_distance[i] = (ray->pos[i] - ray->tile[i])
			* ray->delta_distance[i];
	}
	else
	{
		ray->step[i] = 1;
		ray->side_distance[i] = (ray->tile[i] + 1.0 - ray->pos[i])
			* ray->delta_distance[i];
	}
}
