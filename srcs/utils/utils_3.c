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

void	check_rgb_character(char **data_file, char **s_line,
			t_cub3d *cub3D, char **s_rgb)
{
	int	i;
	int	j;

	i = -1;
	while (s_rgb[++i])
	{
		j = -1;
		while (s_rgb[i][++j])
		{
			if (!ft_isdigit(s_rgb[i][j]) && s_rgb[i][j] != '\n')
			{
				free_splits(s_rgb);
				free_arrays(data_file, s_line, cub3D);
			}
		}
	}
}

void	*ft_pixelset(void *s, int c, size_t n)
{
	size_t	i;
	int		*aux;

	i = 0;
	aux = s;
	while (i < n)
	{
		aux[i] = c;
		i++;
	}
	return (s);
}


int	get_color(char *str)
{
	int		color;
	char	**rgb;

	rgb = ft_split(str, ',');
	color = ft_atoi(rgb[0]);
	color = color << 8;
	color += ft_atoi(rgb[1]);
	color = color << 8;
	color += ft_atoi(rgb[2]);
	free_splits(rgb);
	return (color);
}

double	ft_abs(double n)
{
	if (n < 0)
		return (-n);
	return (n);
}