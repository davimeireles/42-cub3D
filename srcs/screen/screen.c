/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:09:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/10 13:56:53 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	screen_loader(t_cub3d *cub3d)
{
	background_loader(cub3d);
	raycaster(cub3d);
	minimap_loader(cub3d);
/* 	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->screen->north->img_ptr, 50, 50); */
}

void    background_loader(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->screen->ceiling->img_ptr, 0, 0);
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->screen->floor->img_ptr, 0, cub3d->screen->height / 2);
}

void	minimap_loader(t_cub3d *cub3d)
{
	int mm_x;
	int mm_y;
	
	mm_x = -2;
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->minimap->bkg->img_ptr, SCREEN_X - 135, 25);
	while (mm_x <= 2)
	{
		mm_y = -2;
		while (mm_y <= 2)
		{
			print_tile(cub3d, (int) cub3d->player->y + mm_y, (int) cub3d->player->x + mm_x, mm_y, mm_x);
			mm_y++;
		}
		mm_x++;
	}
	mlx_put_image_to_window(cub3d->connection, cub3d->window,
		cub3d->minimap->player->img_ptr, SCREEN_X - 135 + 50, 25 + 50);
}
