
#include "cub3d.h"

void	check_map_name(char *input)
{
	size_t	i;

	i = ft_strlen(input);
	if (!(input[i - 1] == 'b' && input[i - 2] == 'u'
		  && input[i - 3] == 'c' && input[i - 4] == '.'
		  && input[i - 5]))
		p_error(MAP_NAME);
}

void	check_file(char *input)
{
	int	fd;

	fd = open(input, O_RDONLY);
	if (fd == -1)
		p_error(OPEN_ERROR);
}

void	check_map_config(int fd)
{
	char	*line;
	int 	configs;

	line = get_next_line(fd);
	
}
