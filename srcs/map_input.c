/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:03:06 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/10 18:03:06 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_lines(char *input, t_textures *textures);
static void	fill_map(char *input, char **map, t_textures *textures);
static char **final_map(char **map, int total_rows);

static int	count_lines(char *input, t_textures *textures)
{
	int		fd;
	int		rows;
	int		total_rows;
	char	*line;

	fd = open(input, O_RDONLY);
	rows = 0;
	total_rows = 0;
	line = get_next_line(fd);
	while (line)
	{
		rows++;
		if (rows > textures->start_map)
			total_rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (total_rows);
}

static void	fill_map(char *input, char **map, t_textures *textures)
{
	int		fd;
	int		rows;
	int 	lines;
	char	*line;

	fd = open(input, O_RDONLY);
	line = get_next_line(fd);
	rows = 0;
	lines = 0;
	while (line)
	{
		if (rows > textures->start_map)
		{
			map[lines] = ft_strdup(line);
			lines++;
		}
		rows++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}


char	**input_map(char *input, t_textures *textures)
{
	int		total_rows;
	char	**map = NULL;

	total_rows = count_lines(input, textures);
	map = ft_calloc(sizeof(char *), total_rows);
	fill_map(input, map, textures);
	return (final_map(map, total_rows));
}

static char **final_map(char **map, int total_rows)
{
	int		i;
	int 	j;
	int		start;
	char	*t_line;
	char	**new_map;

	i = 0;
	start = 0;
	j = 0;
	while (map[i])
	{
		t_line = ft_strtrim(map[i], " ");
		if (!ft_strcmp(t_line, "\n")) {
			start++;
		}
			else
			{
				free(t_line);
				break;
			}
		free(t_line);
		i++;
	}
	i = total_rows - 2;
	while(i >= 0)
	{
		t_line = ft_strtrim(map[i], " ");
		if (ft_strcmp(t_line, "\n"))
		{
			free(t_line);
			break;
		}
		i--;
	}
	new_map = ft_calloc(sizeof(char *), (i - start + 1));
	while(start <= i)
		new_map[j++] = ft_strdup(map[start++]);
	free_splits(map, NULL);
	return (new_map);
}

/*
static void	parsing_map(int fd)
{
	void	flood_fill(char **map, int i, int j)
	{
		if (map[i][j] == '1' || map[i][j] == 'G')
			return ;
		map[i][j] = 'G';
		flood_fill(map, i + 1, j);
		flood_fill(map, i - 1, j);
		flood_fill(map, i, j + 1);
		flood_fill(map, i, j - 1);
}
*/
