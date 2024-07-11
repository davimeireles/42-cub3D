/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 23:12:04 by txisto-d          #+#    #+#             */
/*   Updated: 2024/07/10 03:23:55 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_cub(t_cub3d **cub3d)
{
	*cub3d = ft_calloc(sizeof(t_cub3d), 1);
	(*cub3d)->map = ft_calloc(sizeof(t_map), 1);
	(*cub3d)->map->textures = ft_calloc(sizeof(t_textures), 1);
	(*cub3d)->map->textures->flood = ft_calloc(sizeof(t_flood_aux), 1);
	(*cub3d)->screen = ft_calloc(sizeof(t_screen), 1);
    (*cub3d)->player = ft_calloc(sizeof(t_player), 1);
	(*cub3d)->minimap = ft_calloc(sizeof(t_minimap), 1);
	(*cub3d)->raycaster = ft_calloc(sizeof(t_raycaster), 1);
}