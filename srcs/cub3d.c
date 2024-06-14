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

static void	initialize_textures(t_cub3d **cub3d);
static void	initialize_map(t_cub3d **cub3d);

void	initialize_cub(t_cub3d **cub3d)
{
	*cub3d = ft_calloc(sizeof(t_cub3d), 1);
	(*cub3d)->map = ft_calloc(sizeof(t_map), 1);
	(*cub3d)->map->textures = ft_calloc(sizeof(t_textures), 1);
	initialize_map(cub3d);
	initialize_textures(cub3d);
//	cub3d->connection = mlx_init();
//	cub3d->window = mlx_new_window(cub3d->connection, 1920, 1080, "cub3D");
//	sleep(10);
}

static void	initialize_textures(t_cub3d **cub3d)
{
	(*cub3d)->map->textures->we = 0;
	(*cub3d)->map->textures->no = 0;
	(*cub3d)->map->textures->c = 0;
	(*cub3d)->map->textures->ea = 0;
	(*cub3d)->map->textures->f = 0;
	(*cub3d)->map->textures->so = 0;

	(*cub3d)->map->textures->file_rows = 0;
}

static void	initialize_map(t_cub3d **cub3d)
{
	(*cub3d)->map->p_position[0] = 0;
	(*cub3d)->map->p_position[1] = 0;
	(*cub3d)->map->start_map = 0;
	(*cub3d)->map->rows = 0;
	(*cub3d)->map->columns = 0;
}