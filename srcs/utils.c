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

void	init_stack(t_textures *textures)
{
	textures->we = 0;
	textures->no = 0;
	textures->c = 0;
	textures->ea = 0;
	textures->f = 0;
	textures->so = 0;
}

void	free_memory(t_cub3d *cub3D)
{
	if (cub3D)
	{
		if (cub3D->map)
		{
			if (cub3D->map->f_map)
				free_splits(cub3D->map->f_map, NULL);
			free(cub3D->map);
		}
		free(cub3D);
	}
}

void	free_splits(char **split, char *line)
{
	int i = 0;

	if (line)
		free(line);
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

void print_colored_char(char c)
{
	switch (c)
	{
		case '1':
			ft_printf("\033[41m \033[0m");
			break;
		case '0':
			ft_printf("\033[47m \033[0m");
			break;
		case 'x':
			ft_printf("\033[41m \033[0m");
			break;
		case 'N':
			ft_printf("\033[42m \033[0m");
			break;
		case 'S':
			ft_printf("\033[42m \033[0m");
			break;
		case 'E':
			ft_printf("\033[42m \033[0m");
			break;
		case 'W':
			ft_printf("\033[42m \033[0m");
			break;
		default:
			ft_printf(" ");
			break;
	}
}

void print_colored_matrix(char *matrix[])
{
	for (int i = 0; matrix[i]; i++)
	{
		for (char *p = matrix[i]; *p != '\0'; p++)
			print_colored_char(*p);
		ft_printf("\n");
	}
}