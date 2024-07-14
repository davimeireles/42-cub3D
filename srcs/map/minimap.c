/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:21:27 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/14 19:43:36 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tile(t_cub3d *cub3d, int x, int y, int *mm_pair)
{
	if (x < 0 || y < 0 || x >= cub3d->map->columns || y >= cub3d->map->rows)
		return ;
	if (cub3d->map->f_map[y][x] == '1')
	{
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->wall->img_ptr, SCREEN_X - 90 + (mm_pair[1] * 10),
			80 + (mm_pair[0] * 10));
	}
	else
	{
		mlx_put_image_to_window(cub3d->connection, cub3d->window,
			cub3d->minimap->floor->img_ptr, SCREEN_X - 90 + (mm_pair[1] * 10),
			80 + (mm_pair[0] * 10));
	}
}
