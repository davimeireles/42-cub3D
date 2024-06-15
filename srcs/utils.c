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

void	free_memory(t_cub3d *cub3D)
{
	if (cub3D)
	{
		if (cub3D->map)
		{
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

void	print_colored_char(char c)
{
	if (c == '0')
		ft_printf("\033[47m \033[0m");
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		ft_printf("\033[42m \033[0m");
	else
		ft_printf("\033[41m \033[0m");
}

void	print_colored_matrix(char *matrix[])
{
	/* change for while */
	for (int i = 0; matrix[i]; i++)
	{
		for (char *p = matrix[i]; *p != '\0'; p++)
			print_colored_char(*p);
		ft_printf("\n");
	}
}

int	count_words(char *row)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (row[i])
	{
		while (row[i] && (row[i] == ' ' || row[i] == '\t' || row[i] == '\n'))
			i++;
		if (row[i])
			words++;
		while (row[i] && row[i] != ' ' && row[i] != '\t')
			i++;
	}
	return (words);
}

void	count_file_rows(int fd, t_textures *textures)
{
	char	*row;

	row = get_next_line(fd);
	while (row)
	{
		textures->file_rows++;
		free(row);
		row = get_next_line(fd);
	}
	free(row);
}

char	**pass_data_array(int fd, t_textures *textures)
{
	char	**data_file;
	char	*row;
	int		i;

	i = 0;
	data_file = ft_calloc(sizeof(char *), textures->file_rows + 1);
	if (!data_file)
		return (NULL);
	row = get_next_line(fd);
	while (row)
	{
		data_file[i] = ft_strdup(row);
		if (!data_file[i])
		{
			free_splits(data_file);
			return (NULL);
		}
		free(row);
		row = get_next_line(fd);
		i++;
	}
	free(row);
	return (data_file);
}

int	find_map_start(char **data_info)
{
	int		i;
	char	**s_line;

	i = -1;
	while (data_info[++i])
	{
		s_line = ft_split(data_info[i], ' ');
		if (!ft_strcmp(s_line[0], "NO") || !ft_strcmp(s_line[0], "SO")
			|| !ft_strcmp(s_line[0], "WE") || !ft_strcmp(s_line[0], "EA")
			|| !ft_strcmp(s_line[0], "F") || !ft_strcmp(s_line[0], "C")
			|| !ft_strcmp(s_line[0], "\n"))
		{
			free_splits(s_line);
			continue ;
		}
		else
		{
			free_splits(s_line);
			return (i);
		}
	}
	return (i);
}
