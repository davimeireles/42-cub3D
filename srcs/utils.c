/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 15:36:10 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/08 15:36:10 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_colored_char(char c);

void	free_memory(t_cub3d *cub3D)
{
	if (cub3D)
	{
		if (cub3D->map)
		{
			if (cub3D->map->textures->flood)
				free(cub3D->map->textures->flood);
			if (cub3D->map->textures)
				free(cub3D->map->textures);
			if (cub3D->map->f_map)
				free_splits(cub3D->map->f_map);
			free(cub3D->map);
		}
		free(cub3D);
	}
}

void	free_splits(char **split)
{
	int	i;

	i = 0;
	if (split)
	{
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free (split);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	while (*s1 == *s2 && *s1 && *s2)
	{
		s1++;
		s2++;
	}
	if ((!*s1) && (!*s2))
		return (0);
	if (*s1 > *s2)
		return (*s1 - *s2);
	else if (*s1 < *s2)
		return (*s1 - *s2);
	return (0);
}

static void	print_colored_char(char c)
{
	if (c == '0' || c == 'x')
		ft_printf("\033[47m \033[0m");
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		ft_printf("\033[42m \033[0m");
	else
		ft_printf("\033[41m \033[0m");
}

void	print_colored_matrix(char *matrix[])
{
	int		i;
	char	*p;

	i = 0;
	while (matrix[i])
	{
		p = matrix[i];
		while (*p != '\0')
		{
			print_colored_char(*p);
			p++;
		}
		ft_printf("\n");
		i++;
	}
}
