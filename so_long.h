/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:22:05 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/08 16:23:56 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/home/hqannouc/minilibx-linux/mlx.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"

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
	void	*coll_img;
	void	*player_img;
	void	*exit_img;
	void	*wall_img;
	void	*bg_img;
}	t_map;

void	print_error(int n);
void	free_map(char **map);

void	height_width(t_map **map_info, char **map);
char	**return_map(char *filename);

void	find_elements(t_map **map_info, char **map);
void	flood_fill(t_map *info, int x, int y, char **visited);
char	**duplicate_map(t_map *map_info, char **map);
int		check_valid_path(char **map);
int		validate_map(t_map **map_info, char **map);
void	full_free(t_map *game);
void	close_window(t_map *game);

void	xpm_to_img(t_map *game);
void	render_map(t_map *game);

#endif