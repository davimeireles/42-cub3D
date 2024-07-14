/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 06:36:22 by dmeirele          #+#    #+#             */
/*   Updated: 2024/07/14 20:21:29 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_cub3d *cub3d)
{
	if (cub3d->map->f_map[(int)(cub3d->player->x + cub3d->player->dir_x
			* cub3d->player->speed)][(int)(cub3d->player->y)] != '1')
		cub3d->player->x += cub3d->player->dir_x * cub3d->player->speed;
	if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y
			+ cub3d->player->dir_y * cub3d->player->speed)] != '1')
		cub3d->player->y += cub3d->player->dir_y * cub3d->player->speed;
	return (1);
}

int	move_back(t_cub3d *cub3d)
{
	if (cub3d->map->f_map[(int)(cub3d->player->x - cub3d->player->dir_x
			* cub3d->player->speed)][(int)(cub3d->player->y)] != '1')
		cub3d->player->x -= cub3d->player->dir_x * cub3d->player->speed;
	if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y
		- cub3d->player->dir_y * cub3d->player->speed)] != '1')
		cub3d->player->y -= cub3d->player->dir_y * cub3d->player->speed;
	return (-1);
}

int	move_left(t_cub3d *cub3d)
{
	double	perp_dir_x;
	double	perp_dir_y;

	perp_dir_x = -cub3d->player->dir_y;
	perp_dir_y = cub3d->player->dir_x;
	if (cub3d->map->f_map[(int)(cub3d->player->x + perp_dir_x
			* cub3d->player->speed)][(int)(cub3d->player->y)] != '1')
		cub3d->player->x += perp_dir_x * cub3d->player->speed;
	if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y
		+ perp_dir_y * cub3d->player->speed)] != '1')
		cub3d->player->y += perp_dir_y * cub3d->player->speed;
	return (-1);
}

int	move_right(t_cub3d *cub3d)
{
	double	perp_dir_x;
	double	perp_dir_y;

	perp_dir_x = cub3d->player->dir_y;
	perp_dir_y = -cub3d->player->dir_x;
	if (cub3d->map->f_map[(int)(cub3d->player->x + perp_dir_x
			* cub3d->player->speed)][(int)(cub3d->player->y)] != '1')
		cub3d->player->x += perp_dir_x * cub3d->player->speed;
	if (cub3d->map->f_map[(int)(cub3d->player->x)][(int)(cub3d->player->y
		+ perp_dir_y * cub3d->player->speed)] != '1')
		cub3d->player->y += perp_dir_y * cub3d->player->speed;
	return (1);
}
