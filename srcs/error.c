
# include "cub3d.h"

void	p_error(e_error type)
{
	if (type == N_ARGS)
		write(2, "Invalid number of arguments.\n", 29);
	else if (type == MAP_NAME)
		write(2, "Invalid file name.\n", 19);
	else if (type == OPEN_ERROR)
		write (2, "Error trying to open the file.\n", 31);
	exit (EXIT_FAILURE);
}