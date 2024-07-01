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

static void	initialize_map(t_cub3d **cub3d);
static void	initialize_textures(t_cub3d **cub3d);
static void	initialize_flood_aux(t_cub3d **cub3D);
static void initialize_image_struct(t_cub3d **cub3D);

void	initialize_cub(t_cub3d **cub3d)
{
	*cub3d = ft_calloc(sizeof(t_cub3d), 1);
	(*cub3d)->map = ft_calloc(sizeof(t_map), 1);
	(*cub3d)->map->textures = ft_calloc(sizeof(t_textures), 1);
	(*cub3d)->map->textures->flood = ft_calloc(sizeof(t_flood_aux), 1);
	(*cub3d)->connection = NULL;
	(*cub3d)->window = NULL;
	initialize_map(cub3d);
	(*cub3d)->map->text_imgs = ft_calloc(sizeof(t_img), (*cub3d)->map->n_textures);
	initialize_textures(cub3d);
	initialize_flood_aux(cub3d);
	initialize_image_struct(cub3d);
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
	(*cub3d)->map->n_textures = 6;
	(*cub3d)->map->north = NULL;
	(*cub3d)->map->south = NULL;
	(*cub3d)->map->west = NULL;
	(*cub3d)->map->east = NULL;
	(*cub3d)->map->ceiling = NULL;
	(*cub3d)->map->floor = NULL;
}

static void	initialize_flood_aux(t_cub3d **cub3D)
{
	(*cub3D)->map->textures->flood->u = false;
	(*cub3D)->map->textures->flood->d = false;
	(*cub3D)->map->textures->flood->r = false;
	(*cub3D)->map->textures->flood->l = false;
	(*cub3D)->map->textures->flood->u_r = false;
	(*cub3D)->map->textures->flood->u_l = false;
	(*cub3D)->map->textures->flood->d_r = false;
	(*cub3D)->map->textures->flood->d_l = false;
}

static void initialize_image_struct(t_cub3d **cub3D)
{
		(*cub3D)->map->text_imgs->data = NULL;
		(*cub3D)->map->text_imgs->img_ptr = NULL;
		(*cub3D)->map->text_imgs->width = 0;
		(*cub3D)->map->text_imgs->height = 0;
}
