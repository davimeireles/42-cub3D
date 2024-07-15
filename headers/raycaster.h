/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:50:25 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/15 17:51:31 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTER_H
# define RAYCASTER_H

# include "cub3d.h"

void	raycaster(t_cub3d *cub3d);
void	calculate_ray(t_ray *ray, int i);
void	calculate_distance(t_ray *ray, int i);
void	dda_algorithm(t_cub3d *cub3d, t_ray *ray);
void	draw_ray(t_cub3d *cub3d, t_ray *ray, int x);
t_img	*vertical_line(t_cub3d *cub3d);
void	put_column(t_cub3d *cub3d, int x, int height, t_img texture);
void	calculate_wall_x(t_cub3d *cub3d, int dimension);

#endif