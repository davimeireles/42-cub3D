/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:15:09 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/17 20:07:40 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

/*
███    ███ ██ ███    ██ ██ ███    ███  █████  ██████
████  ████ ██ ████   ██ ██ ████  ████ ██   ██ ██   ██
██ ████ ██ ██ ██ ██  ██ ██ ██ ████ ██ ███████ ██████
██  ██  ██ ██ ██  ██ ██ ██ ██  ██  ██ ██   ██ ██
██      ██ ██ ██   ████ ██ ██      ██ ██   ██ ██
*/

/**
 * @brief Select the tile to be printed on the minimap.
 * @param cub3d the struct containing all the data.
 * @param x the x coordinate of the tile.
 * @param y the y coordinate of the tile.
 * @param mm_x the x coordinate of the tile on the minimap.
 * @param mm_y the y coordinate of the tile on the minimap.
 */
void	print_tile(t_cub3d *cub3d, int x, int y, int *mm_pair);
void	tile_n(t_player *player, t_cub3d *cub3d);
void	tile_s(t_player *player, t_cub3d *cub3d);
void	tile_w(t_player *player, t_cub3d *cub3d);
void	tile_e(t_player *player, t_cub3d *cub3d);
void	ft_put_img(t_cub3d *cub3d, int pos[XY],int size[XY], int color);
#endif