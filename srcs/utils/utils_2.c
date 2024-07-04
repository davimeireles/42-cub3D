/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 17:48:56 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/16 17:48:56 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	free_arrays(char **data_file, char **s_line, t_cub3d *cub3D)
{
	free_splits(data_file);
	free_splits(s_line);
	p_error(RGB, cub3D);
}
