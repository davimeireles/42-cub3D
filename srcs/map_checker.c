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

void	free_splits(char **split);

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
}

void	check_map_config(int fd, t_textures *textures)
{
	char	*line;
	char	**split_line;

	line = get_next_line(fd);
	while (line)
	{
		printf("%c", line[ft_strlen(line) - 1]);
		split_line = ft_split(line, ' ');
		if (!ft_strcmp(split_line[0], "NO") && split_line[1] && !split_line[2]) {
			textures->no++;
		}
		else if (!ft_strcmp(split_line[0], "SO") && split_line[1] && !split_line[2]) {
			textures->so++;
		}
		else if (!ft_strcmp(split_line[0], "WE") && split_line[1] && !split_line[2]) {
			textures->we++;
		}
		else if (!ft_strcmp(split_line[0], "EA") && split_line[1] && !split_line[2])
			textures->ea++;
		else if (!ft_strcmp(split_line[0], "F") && split_line[1] && !split_line[2])
			textures->f++;
		else if (!ft_strcmp(split_line[0], "C") && split_line[1] && !split_line[2])
			textures->c++;
		free(line);
		free_splits(split_line);
		line = get_next_line(fd);
	}
	if (textures->no != 1 || textures->so != 1 || textures->we != 1
		|| textures->ea != 1 || textures->f != 1 || textures->c != 1)
		p_error(CONFIGS);
}

/* Functions to move to other files. \/ */

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

void	free_splits(char **split)
{
	int i = 0;

	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free (split);
}

void	init_stack(t_textures *textures)
{
	textures->we = 0;
	textures->no = 0;
	textures->c = 0;
	textures->ea = 0;
	textures->f = 0;
	textures->so = 0;
}
