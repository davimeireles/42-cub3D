/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 15:23:29 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/04 15:24:15 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include "libft.h"
# include <stdio.h>

/*******          STRUCTS          *******/

typedef enum e_error
{
	N_ARGS,
	MAP_NAME,
	OPEN_ERROR
}	t_error;

typedef struct s_configs
{

}	t_configs;

/*
 * NO -> North Texture
 * SO -> South Texture
 * WE -> West Texture
 * EA -> East Texture
 * F -> Floor color
 * C -> Ceiling color
*/

typedef enum e_textures
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	e_textures;

typedef struct s_textures
{
	int NO;
	int SO;
	int WE;
	int EA;
	int	F;
	int C;
}	t_textures;


/*******          FUNCTIONS          *******/

/* main.c */

int main(int argc, char **argv);

/* error.c */

void	p_error(e_error type);

/* map_checker.c */

void	check_map_name(char *input);
void	check_file(char *input);
void	check_map_config(int fd);

#endif