/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:22:57 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/05 20:33:44 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_textures textures;
	t_cub3d	*cub3d;

	 if (argc == 2)
	{
		initialize_cub(&cub3d);
		init_stack(&textures);
		check_file(argv[1], &textures);
		cub3d->map->f_map = input_map(argv[1], &textures, cub3d);
		map_checker(cub3d);
		print_colored_matrix(cub3d->map->f_map);
		free_memory(cub3d);
	}
	else
		p_error(N_ARGS);
	return (0);
}
