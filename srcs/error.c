/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:55:14 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/14 12:55:14 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	p_error(t_error type, t_cub3d *cub3d)
{
	if (type == N_ARGS)
		ft_printf("Error\nInvalid number of arguments.\n");
	else if (type == MAP_NAME)
		ft_printf("Error\nInvalid file name.\n");
	else if (type == OPEN_ERROR)
		ft_printf("Error\nError trying to open the file.\n");
	else if (type == CONFIGS)
		ft_printf("Error\nMissing/Wrong configuration in the file.\n");
	else if (type == MEMORY)
		ft_printf("Error\nBad alloc error.\n");
	else if (type == INVALID_MAP)
		ft_printf("Error\nInvalid map.\n");
	free_memory(cub3d);
	exit(EXIT_FAILURE);
}
