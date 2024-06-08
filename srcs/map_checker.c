/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:27:27 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/06 18:06:14 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	loop_checker_config(int fd, t_textures *textures);
static void	check_if_configs_above(char *line, char *t_line, char **split_line, t_textures *textures);

void	check_map_name(char *input)
{
	size_t	i;

	i = ft_strlen(input);
	if (!(input[i - 1] == 'b' && input[i - 2] == 'u'
			&& input[i - 3] == 'c' && input[i - 4] == '.'
			&& input[i - 5]))
		p_error(MAP_NAME);
}

void	check_file(char *input, t_textures *textures)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		p_error(OPEN_ERROR);
	check_map_config(fd, textures);
	close(fd);
}

void	check_map_config(int fd, t_textures *textures)
{
	loop_checker_config(fd, textures);
}

static void	loop_checker_config(int fd, t_textures *textures)
{
	char	*t_line;
	char	*line;
	char	**split_line;

	line = get_next_line(fd);
	while (line)
	{
		t_line = ft_strtrim(line, " ");
		split_line = ft_split(t_line, ' ');
		if (!ft_strcmp(split_line[0], "NO") && (split_line[1] && split_line[1][0] != '\n') && (!split_line[2] || split_line[2][0] == '\n'))
			textures->no++;
		else if (!ft_strcmp(split_line[0], "SO") && (split_line[1] && split_line[1][0] != '\n') && (!split_line[2] || split_line[2][0] == '\n'))
			textures->so++;
		else if (!ft_strcmp(split_line[0], "WE") && (split_line[1] && split_line[1][0] != '\n') && (!split_line[2] || split_line[2][0] == '\n'))
			textures->we++;
		else if (!ft_strcmp(split_line[0], "EA") && (split_line[1] && split_line[1][0] != '\n') && (!split_line[2] || split_line[2][0] == '\n'))
			textures->ea++;
		else if (!ft_strcmp(split_line[0], "F") && (split_line[1] && split_line[1][0] != '\n') && (!split_line[2] || split_line[2][0] == '\n'))
			textures->f++;
		else if (!ft_strcmp(split_line[0], "C") && (split_line[1] && split_line[1][0] != '\n') && (!split_line[2] || split_line[2][0] == '\n'))
			textures->c++;
		check_if_configs_above(line, t_line, split_line, textures);
		free_splits(split_line, line);
		free(t_line);
		line = get_next_line(fd);
	}
}

static void	check_if_configs_above(char *line, char *t_line, char **split_line, t_textures *textures)
{
		if ((ft_strcmp(split_line[0], "NO") && ft_strcmp(split_line[0], "SO")
			 && ft_strcmp(split_line[0], "WE") && ft_strcmp(split_line[0], "EA")
			 && ft_strcmp(split_line[0], "F") && ft_strcmp(split_line[0], "C")
			 && split_line[0][0] != '\n'))
		{
			if (textures->no != 1 || textures->so != 1 || textures->we != 1
			|| textures->ea != 1 || textures->f != 1 || textures->c != 1)
			{
				free_splits(split_line, line);
				free(t_line);
				p_error(CONFIGS);
			}
		}
}
