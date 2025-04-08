/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:55:37 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:19:34 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	xpm_to_img(t_map *game)
{
	int	img_height;
	int	img_width;
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, 32 * game->height, 32 * game->width, "so_long");
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "wall.xpm", &img_height, &img_width);
	mlx_loop(game->mlx);
}