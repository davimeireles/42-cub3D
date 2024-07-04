/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 16:09:52 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/04 18:18:14 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    background_loader(t_cub3d *cub3d)
{
	mlx_put_image_to_window(cub3d->connection, cub3d->window, cub3d->screen->ceiling->img_ptr, 0, 0);
	mlx_put_image_to_window(cub3d->connection, cub3d->window, cub3d->screen->floor->img_ptr, 0, cub3d->screen->heigh / 2);
}
