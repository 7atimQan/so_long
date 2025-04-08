/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:22:05 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:15:14 by hqannouc         ###   ########.fr       */
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

typedef struct s_map
{
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		height;
	int		width;
	int		c_count;
	void	*mlx;
	void	*window;
	char	**map;
	void	*collectible_img;
	void	*player_img;
	void	*exit_img;
	void	*wall_img;
	void	*space_img;
}	t_map;

void	free_map(char **map);
char	**return_map(char *filename);
void	find_elements(t_map **map_info, char **map);
void	flood_fill(t_map *info, char **map, int x, int y, char **visited);
void	height_width(t_map **map_info, char **map);
int		check_valid_path(char **map);
int		validate_map(t_map **map_info, char **map);
char	**duplicate_map(t_map *map_info, char **map);
void	print_error(int n);
void	xpm_to_img(t_map *game);

#endif