/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 20:07:25 by txisto-d          #+#    #+#             */
/*   Updated: 2024/06/05 20:38:09 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_cub(t_cub3d **cub3d)
{
	*cub3d = ft_calloc(sizeof(t_cub3d), 1);
	(*cub3d)->map = ft_calloc(sizeof(t_map), 1);
//	cub3d->connection = mlx_init();
//	cub3d->window = mlx_new_window(cub3d->connection, 1920, 1080, "cub3D");
//	sleep(10);
}