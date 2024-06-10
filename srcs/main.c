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
	(void) argc;
	(void) argv;
	t_textures textures;
/*	t_cub3d	*cub3d;

	cub3d = NULL;
	initialize_cub(cub3d);*/
	 if (argc == 2)
	{
		init_stack(&textures);
		check_file(argv[1], &textures);
		check_map(argv[1]);
//		initialize_cub(cub3d);
	}
	else
		p_error(N_ARGS);
	return (0);
}
