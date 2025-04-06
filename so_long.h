/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:22:05 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/06 16:22:06 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/home/hqannouc/minilibx-linux/mlx.h"
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
void	find_player(char **map, int *x, int *y);
void	flood_fill(char **map, int x, int y, char **visited);
int		check_valid_path(char **map);
char	**duplicate_map(char **map);
int		validate_map(char **map);
void	print_error(int n);

#endif