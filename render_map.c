/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:55:37 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/09 14:51:44 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	full_free(t_map *game)
{
	if (game->bg_img)
		mlx_destroy_image(game->mlx, game->bg_img);
	if (game->coll_img)
		mlx_destroy_image(game->mlx, game->coll_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exit_img)
		mlx_destroy_image(game->mlx, game->exit_img);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map);
	free(game);
}

void	error_exit(t_map *game, int n)
{
	full_free(game);
	print_error(n);
	exit(1);
}

int	close_window(t_map *game)
{
	full_free(game);
	exit(0);
}

void	xpm_to_img(t_map *game)
{
	int img_height, (img_width);
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit(game, 7);
	game->window = mlx_new_window(game->mlx, 64 * game->width, 64
			* game->height, "so_long");
	if (!game->window)
		error_exit(game, 7);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./textures/Wall.xpm",
			&img_height, &img_width);
	game->bg_img = mlx_xpm_file_to_image(game->mlx, "./textures/BG.xpm",
			&img_height, &img_width);
	game->coll_img = mlx_xpm_file_to_image(game->mlx, "./textures/Coll.xpm",
			&img_height, &img_width);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./textures/Exit.xpm",
			&img_height, &img_width);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./textures/Player.xpm",
			&img_height, &img_width);
	if (!game->wall_img || !game->bg_img || !game->coll_img || !game->exit_img
		|| !game->player_img)
		error_exit(game, 7);
}

void	render_map(t_map *game)
{
	int (x), y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->wall_img,
					x * 64, y * 64);
			else if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->window, game->bg_img,
					x * 64, y * 64);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->window,
					game->player_img, x * 64, y * 64);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->window, game->exit_img,
					x * 64, y * 64);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->window, game->coll_img,
					x * 64, y * 64);
			x++;
		}
		y++;
	}
}
