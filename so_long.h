#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

void	free_map(char **map);
char	**return_map(char *filename);

#endif