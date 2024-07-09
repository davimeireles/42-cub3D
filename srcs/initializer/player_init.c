/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:40:53 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/08 19:53:22 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void    player_direction(t_cub3d *cub3d);

void    player_init(t_cub3d *cub3d)
{
    cub3d->player->x = (float) cub3d->map->p_position[0] + 0.5;
    cub3d->player->y = (float) cub3d->map->p_position[1] + 0.5;
    cub3d->player->fov = FOV;
    cub3d->player->speed = 0.1;
    player_direction(cub3d);
}

static void    player_direction(t_cub3d *cub3d)
{
    if (cub3d->map->p_direction == 'N')
        cub3d->player->dir = 0;
    else if (cub3d->map->p_direction == 'E')
        cub3d->player->dir = 90;
    else if (cub3d->map->p_direction == 'S')
        cub3d->player->dir = 180;
    else if (cub3d->map->p_direction == 'W')
        cub3d->player->dir = 270;
}