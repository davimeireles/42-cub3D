/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:40:53 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/11 22:10:27 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    player_direction(t_cub3d *cub3d);

void    player_init(t_cub3d *cub3d)
{
    cub3d->player->x = (double) cub3d->map->p_position[0] + 0.5;
    cub3d->player->y = (double) cub3d->map->p_position[1] + 0.5;
    cub3d->player->fov = FOV;
    cub3d->player->speed = 0.1;
    cub3d->player->rotation = 0.025;
    player_direction(cub3d);
}

static void    player_direction(t_cub3d *cub3d)
{
    if (cub3d->map->p_direction == 'N')
    {
        cub3d->player->dir_x = -1;
        cub3d->player->dir_y = 0;
        cub3d->player->plane_x = 0;
        cub3d->player->plane_y = 0.66;
    }
    else if (cub3d->map->p_direction == 'E')
    {
        cub3d->player->dir_x = 0;
        cub3d->player->dir_y = 1;
        cub3d->player->plane_x = 0.66;
        cub3d->player->plane_y = 0;
    }
    else if (cub3d->map->p_direction == 'S')
    {
        cub3d->player->dir_x = 1;
        cub3d->player->dir_y = 0;
        cub3d->player->plane_x = 0;
        cub3d->player->plane_y = -0.66;
    }
    else if (cub3d->map->p_direction == 'W')
    {
        cub3d->player->dir_x = 0;
        cub3d->player->dir_y = -1;
        cub3d->player->plane_x = -0.66;
        cub3d->player->plane_y = 0;
    }
}