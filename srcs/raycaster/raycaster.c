/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:33:42 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/09 14:44:08 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void    calculate_ray(t_ray *ray, int i);
void    calculate_distance(t_ray *ray, int i);
void    dda_algorithm(t_cub3d *cub3d, t_ray *ray);
void    draw_ray(t_cub3d *cub3d, t_ray *ray, int x);
void    vertical_line(t_cub3d *cub3d, int start, int end, int x, int color);

void    raycaster(t_cub3d *cub3d)
{
    t_ray   *ray;
    int i;

    i = -1;
    raycaster_init(cub3d);
    ray = &cub3d->raycaster->ray;
    while (++i < SCREEN_X)
    {
        ray->hit = 0;
        calculate_ray(ray, i);
        dda_algorithm(cub3d, ray);
        draw_ray(cub3d, ray, i);
    }
}

void    calculate_ray(t_ray *ray, int i)
{
    ray->camera_x = 2 * i / (double)SCREEN_X - 1;
    ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * ray->camera_x;
    ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * ray->camera_x;
    printf("ray->ray_dir[X]: %f\n ray->ray_dir[Y]: %f\n", ray->ray_dir[X], ray->ray_dir[Y]);
    if (ray->ray_dir[X] == 0)
        ray->delta_distance[X] = 1e30;
    else
        ray->delta_distance[X] = ft_abs(1 / ray->ray_dir[X]);
    if (ray->ray_dir[Y] == 0)
        ray->delta_distance[Y] = 1e30;
    else
        ray->delta_distance[Y] = ft_abs(1 / ray->ray_dir[Y]);
    printf("ray->delta_distance[X]: %f\n ray->delta_distance[Y]: %f\n", ray->delta_distance[X], ray->delta_distance[Y]);
    calculate_distance(ray, X);
    calculate_distance(ray, Y);
}

void    calculate_distance(t_ray *ray, int i)
{
    ray->tile[i] = (int) ray->pos[i];
    if (ray->ray_dir[i] < 0)
    {
        ray->step[i] = -1;
        ray->side_distance[i] = (ray->pos[i] - ray->tile[i]) * ray->delta_distance[i];
    }
    else
    {
        ray->step[i] = 1;
        ray->side_distance[i] = (ray->tile[i] + 1.0 - ray->pos[i]) * ray->delta_distance[i];
    }
}

void    dda_algorithm(t_cub3d *cub3d, t_ray *ray)
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
        if (cub3d->map->f_map[ray->tile[X]][ray->tile[1]] > 0)
            ray->hit = 1;
    }
    if (ray->side == 0)
        ray->perp_wall_distance = (ray->side_distance[X] - ray->delta_distance[X]);
    else
        ray->perp_wall_distance = (ray->side_distance[Y] - ray->delta_distance[Y]);
}

void    draw_ray(t_cub3d *cub3d, t_ray *ray, int x)
{
    int line_height;
    int draw_start;
    int draw_end;
    int color;

    line_height = (int)(SCREEN_Y / ray->perp_wall_distance);
    draw_start = -line_height / 2 + SCREEN_Y / 2;
    if (draw_start < 0)
        draw_start = 0;
    draw_end = line_height / 2 + SCREEN_Y / 2;
    if (draw_end >= SCREEN_Y)
        draw_end = SCREEN_Y - 1;
    color = RED;
    vertical_line(cub3d, draw_start, draw_end, x, color);
}

void    vertical_line(t_cub3d *cub3d, int start, int end, int x, int color)
{
    int i;

    i = start;
    while (i < end)
    {
        mlx_pixel_put(cub3d->connection, cub3d->window, x, i, color);
        i++;
    }
}
