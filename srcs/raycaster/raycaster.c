/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:33:42 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/15 17:51:18 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	raycaster(t_cub3d *cub3d)
{
	t_ray	*ray;
	int		i;

	i = 0;
	raycaster_init(cub3d);
	ray = &cub3d->raycaster->ray;
	while (i < SCREEN_X)
	{
		ray->hit = 0;
		calculate_ray(ray, i);
		dda_algorithm(cub3d, ray);
		draw_ray(cub3d, ray, i);
		i++;
	}
}

void	calculate_ray(t_ray *ray, int i)
{
	ray->camera_x = 2 * i / (double) SCREEN_X - 1;
	ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * ray->camera_x;
	ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * ray->camera_x;
	if (ray->ray_dir[X] == 0)
		ray->delta_distance[X] = 1e30;
	else
		ray->delta_distance[X] = ft_abs(1 / ray->ray_dir[X]);
	if (ray->ray_dir[Y] == 0)
		ray->delta_distance[Y] = 1e30;
	else
		ray->delta_distance[Y] = ft_abs(1 / ray->ray_dir[Y]);
	calculate_distance(ray, X);
	calculate_distance(ray, Y);
}

void	dda_algorithm(t_cub3d *cub3d, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->side_distance[X] < ray->side_distance[Y])
		{
			ray->side_distance[X] += ray->delta_distance[X];
			ray->tile[X] += ray->step[X];
			ray->side = 0;
		}
		else
		{
			ray->side_distance[Y] += ray->delta_distance[Y];
			ray->tile[Y] += ray->step[Y];
			ray->side = 1;
		}
		if (cub3d->map->f_map[ray->tile[X]][ray->tile[Y]] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_distance = (ray->side_distance[X]
				- ray->delta_distance[X]);
	else
		ray->perp_wall_distance = (ray->side_distance[Y]
				- ray->delta_distance[Y]);
}

void	draw_ray(t_cub3d *cub3d, t_ray *ray, int x)
{
	int	line_height;

	line_height = (int)(SCREEN_Y / ray->perp_wall_distance);
	put_column(cub3d, x, line_height, *vertical_line(cub3d));
}

void	put_column(t_cub3d *cub3d, int x, int height, t_img texture)
{
	int	screen_y;
	int	tex_y;
	int	draw_start;
	int	draw_end;
	int	tex_x;

	draw_start = (-height / 2 + SCREEN_Y / 2) - 1;
	if (draw_start < 0)
		draw_start = -1;
	draw_end = height / 2 + SCREEN_Y / 2;
	if (draw_end >= SCREEN_Y)
		draw_end = SCREEN_Y - 1;
	if (cub3d->raycaster->ray.side == 0)
		calculate_wall_x(cub3d, Y);
	else
		calculate_wall_x(cub3d, X);
	tex_x = (int)(cub3d->raycaster->ray.wall_x * (double)64);
	while (++draw_start < draw_end)
	{
		screen_y = draw_start - SCREEN_Y / 2 + height / 2;
		tex_y = screen_y * 64 / height;
		cub3d->screen->screen->data[x + draw_start
			* (cub3d->screen->screen->size_line / 4)]
			= texture.data[tex_x + tex_y * 64];
	}
}
