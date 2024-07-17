/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:21:27 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/17 21:23:51 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_tile(t_cub3d *cub3d, int x, int y, int *mm_pair)
{
	int	i;
	int	j;

	i = 80 + (mm_pair[X] * 10);
	j = 90 + (mm_pair[X] * 10);
	if (x < 0 || y < 0 || x >= cub3d->map->columns || y >= cub3d->map->rows)
		return ;
	if (cub3d->map->f_map[y][x] == '1')
	{
		while (++i <= j)
			ft_pixelset(&cub3d->screen->screen->data[(i * SCREEN_X) - 90
				+ (mm_pair[Y] * 10)], GREY, 10);
	}
	else if (cub3d->map->f_map[y][x] == '0' || cub3d->map->f_map[y][x] == 'N'
		|| cub3d->map->f_map[y][x] == 'S' || cub3d->map->f_map[y][x] == 'W'
		|| cub3d->map->f_map[y][x] == 'E')
	{
		while (++i <= j)
			ft_pixelset(&cub3d->screen->screen->data[(i * SCREEN_X) - 90
				+ (mm_pair[1] * 10)], WHITE, 10);
	}
}

void	tile_n(t_player *player, t_cub3d *cub3d)
{
	if (player->dir_x < -0.66)
	{
		if (player->dir_y > -0.33 && player->dir_y < 0.33)
			ft_put_img(cub3d, (int [XY]){86, 81}, (int [XY]){2, 1}, GREEN);
		if (player->dir_y > 0.33 && player->dir_y < 0.66)
			ft_put_img(cub3d, (int [XY]){84, 81}, (int [XY]){2, 1}, GREEN);
		if (player->dir_y > 0.66 && player->dir_y < 1)
			ft_put_img(cub3d, (int [XY]){82, 81}, (int [XY]){2, 1}, GREEN);
		if (player->dir_y < -0.33 && player->dir_y > -0.66)
			ft_put_img(cub3d, (int [XY]){88, 81}, (int [XY]){2, 1}, GREEN);
		if (player->dir_y < -0.66 && player->dir_y > -1)
			ft_put_img(cub3d, (int [XY]){90, 81}, (int [XY]){2, 1}, GREEN);
	}
}

void	tile_s(t_player *player, t_cub3d *cub3d)
{
	if (player->dir_x > 0.66)
	{
		if (player->dir_y > -0.33 && player->dir_y < 0.33)
			ft_put_img(cub3d, (int [XY]){86, 89}, (int [XY]){2, 1}, GREEN);
		if (player->dir_y > 0.33 && player->dir_y < 0.66)
			ft_put_img(cub3d, (int [XY]){84, 89}, (int [XY]){2, 1}, GREEN);
		if (player->dir_y > 0.66 && player->dir_y < 1)
			ft_put_img(cub3d, (int [XY]){82, 89}, (int [XY]){2, 1}, GREEN);
		if (player->dir_y < -0.33 && player->dir_y > -0.66)
			ft_put_img(cub3d, (int [XY]){88, 89}, (int [XY]){2, 1}, GREEN);
		if (player->dir_y < -0.66 && player->dir_y > -1)
			ft_put_img(cub3d, (int [XY]){90, 89}, (int [XY]){2, 1}, GREEN);
	}
}

void	tile_w(t_player *player, t_cub3d *cub3d)
{
	if (player->dir_y < -0.66)
	{
		if (player->dir_x > -0.33 && player->dir_x < 0.33)
			ft_put_img(cub3d, (int [XY]){90, 85}, (int [XY]){2, 1}, GREEN);
		if (player->dir_x > 0.33 && player->dir_x < 0.66)
			ft_put_img(cub3d, (int [XY]){90, 87}, (int [XY]){2, 1}, GREEN);
		if (player->dir_x > 0.66 && player->dir_x < 1)
			ft_put_img(cub3d, (int [XY]){90, 89}, (int [XY]){2, 1}, GREEN);
		if (player->dir_x < -0.33 && player->dir_x > -0.66)
			ft_put_img(cub3d, (int [XY]){90, 83}, (int [XY]){2, 1}, GREEN);
		if (player->dir_x < -0.66 && player->dir_x > -1)
			ft_put_img(cub3d, (int [XY]){90, 81}, (int [XY]){2, 1}, GREEN);
	}
}

void	tile_e(t_player *player, t_cub3d *cub3d)
{
	if (player->dir_y > 0.66)
	{
		if (player->dir_x > -0.33 && player->dir_x < 0.33)
			ft_put_img(cub3d, (int [XY]){82, 85}, (int [XY]){2, 1}, GREEN);
		if (player->dir_x > 0.33 && player->dir_x < 0.66)
			ft_put_img(cub3d, (int [XY]){82, 87}, (int [XY]){2, 1}, GREEN);
		if (player->dir_x > 0.66 && player->dir_x < 1)
			ft_put_img(cub3d, (int [XY]){82, 89}, (int [XY]){2, 1}, GREEN);
		if (player->dir_x < -0.33 && player->dir_x > -0.66)
			ft_put_img(cub3d, (int [XY]){82, 83}, (int [XY]){2, 1}, GREEN);
		if (player->dir_x < -0.66 && player->dir_x > -1)
			ft_put_img(cub3d, (int [XY]){82, 81}, (int [XY]){2, 1}, GREEN);
	}
}
