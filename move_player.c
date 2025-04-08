/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 15:46:05 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/08 23:52:47 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/keysym.h>

void	handle_exit(t_map *game)
{
	ft_printf("Move count : %d\n", game->move_count);
	ft_printf ("Congratulations !\n");
	close_window(game);
}

void	move_player(t_map *game, int mov_x, int mov_y)
{
	int	new_x;
	int	new_y;
	
	new_x = game->player_x + mov_x;
	new_y = game->player_y + mov_y;
	if (game->map[new_y][new_x] != '1')
	{
		game->move_count++;
		if (game->player_x == game->exit_x && game->player_y == game->exit_y)
		game->map[game->player_y][game->player_x] = 'E';
		else
			game->map[game->player_y][game->player_x] = '0';
		if (game->map[new_y][new_x] == 'C')
			game->c_count--;
		game->player_y = new_y;
		game->player_x = new_x;
		if (game->map[new_y][new_x] == 'E' && game->c_count == 0)
				handle_exit(game);
		game->map[game->player_y][game->player_x] = 'P';
		ft_printf("Move count : %d\n", game->move_count);
		render_map(game);
	}
}

int	key_hook(int key_code, t_map *game)
{
	if (key_code == XK_Escape)
	close_window(game);
	if (key_code == XK_Up)
	move_player(game, 0, -1);
	if (key_code == XK_Down)
	move_player(game, 0, 1);
	if (key_code == XK_Left)
	move_player(game, -1, 0);
	if (key_code == XK_Right)
	move_player(game, +1, 0);
	return (0);
}