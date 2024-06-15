/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmeirele <dmeirele@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 18:01:52 by dmeirele          #+#    #+#             */
/*   Updated: 2024/06/10 18:01:52 by dmeirele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_has_configs(char **data_file, t_cub3d *cub3d);
static void	check_number_args_config(char **data_file, t_cub3d *cub3D,
				int i, int error);
static void	check_if_configs_above(char **data_file, t_cub3d *cub3D);

void	file_checker(char *input, t_cub3d *cub3d)
{
	int		fd;
	size_t	i;

	i = ft_strlen(input);
	if (!(input[i - 1] == 'b' && input[i - 2] == 'u'
			&& input[i - 3] == 'c' && input[i - 4] == '.'
			&& input[i - 5]))
		p_error(MAP_NAME, cub3d);
	fd = open(input, O_RDONLY);
	if (fd == -1)
		p_error(OPEN_ERROR, cub3d);
	count_file_rows(fd, cub3d->map->textures);
	close(fd);
}

void	check_file_config(char *input, t_cub3d *cub3d)
{
	int		fd;
	char	**data_file;

	fd = open(input, O_RDONLY);
	data_file = pass_data_array(fd, cub3d->map->textures);
	close(fd);
	check_has_configs(data_file, cub3d);
	if (cub3d->map->textures->no != 1
		|| cub3d->map->textures->so != 1
		|| cub3d->map->textures->we != 1
		|| cub3d->map->textures->ea != 1
		|| cub3d->map->textures->f != 1
		|| cub3d->map->textures->c != 1)
	{
		free_splits(data_file);
		p_error(CONFIGS, cub3d);
	}
	check_number_args_config(data_file, cub3d, -1, 0);
	check_if_configs_above(data_file, cub3d);
	cub3d->map->start_map = find_map_start(data_file);
	// create a new extract configs to struct
	// fill info inside struct about configurations and make validation
	// using the data_file array
	map_checker(data_file, cub3d);
}

static void	check_has_configs(char **data_file, t_cub3d *cub3d)
{
	int		i;
	char	**s_line;

	i = -1;
	while (data_file[++i])
	{
		s_line = ft_split(data_file[i], ' ');
		if (!ft_strcmp(s_line[0], "NO"))
			cub3d->map->textures->no++;
		else if (!ft_strcmp(s_line[0], "SO"))
			cub3d->map->textures->so++;
		else if (!ft_strcmp(s_line[0], "WE"))
			cub3d->map->textures->we++;
		else if (!ft_strcmp(s_line[0], "EA"))
			cub3d->map->textures->ea++;
		else if (!ft_strcmp(s_line[0], "F"))
			cub3d->map->textures->f++;
		else if (!ft_strcmp(s_line[0], "C"))
			cub3d->map->textures->c++;
		free_splits(s_line);
	}
}

static void	check_number_args_config(char **data_file, t_cub3d *cub3D,
						int i, int error)
{
	char	**s_line;

	while (data_file[++i])
	{
		s_line = ft_split(data_file[i], ' ');
		if (!ft_strcmp(s_line[0], "NO") && count_words(data_file[i]) != 2)
			error = 1;
		else if (!ft_strcmp(s_line[0], "SO") && count_words(data_file[i]) != 2)
			error = 1;
		else if (!ft_strcmp(s_line[0], "WE") && count_words(data_file[i]) != 2)
			error = 1;
		else if (!ft_strcmp(s_line[0], "EA") && count_words(data_file[i]) != 2)
			error = 1;
		else if (!ft_strcmp(s_line[0], "F") && count_words(data_file[i]) != 2)
			error = 1;
		else if (!ft_strcmp(s_line[0], "C") && count_words(data_file[i]) != 2)
			error = 1;
		free_splits(s_line);
	}
	if (error == 1)
	{
		free_splits(data_file);
		p_error(CONFIGS, cub3D);
	}
}

static void	check_if_configs_above(char **data_file, t_cub3d *cub3D)
{
	int		i;
	int		flag;
	char	**s_line;

	i = -1;
	flag = 0;
	while (data_file[++i])
	{
		s_line = ft_split(data_file[i], ' ');
		if (!ft_strcmp(s_line[0], "NO") || !ft_strcmp(s_line[0], "SO")
			|| !ft_strcmp(s_line[0], "WE") || !ft_strcmp(s_line[0], "EA")
			|| !ft_strcmp(s_line[0], "F") || !ft_strcmp(s_line[0], "C"))
			flag++;
		else
		{
			if (flag != 6 && ft_strcmp(s_line[0], "\n"))
			{
				free_splits(s_line);
				free_splits(data_file);
				p_error(CONFIGS, cub3D);
			}
		}
		free_splits(s_line);
	}
}
