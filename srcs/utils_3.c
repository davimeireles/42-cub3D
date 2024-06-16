/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:00:03 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/16 18:00:03 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*padding_aux(char *map, char *line, t_cub3d *cub3D)
{
	int	j;
	int	i;

	j = -1;
	i = 0;
	while (++j < cub3D->map->columns)
	{
		if (map[j])
		{
			if (map[j] == ' ' || map[j] == '\t'
				|| map[j] == '\n' || map[j] == '\0')
				line[i] = 'x';
			else
				line[i] = map[j];
		}
		else
		{
			while (j < cub3D->map->columns)
				line[j++] = 'x';
			break ;
		}
		i++;
	}
	return (line);
}
