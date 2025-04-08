/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:26:35 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/08 23:39:28 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map_info;

	if (argc == 1)
		return (0);
	map_info = malloc(sizeof(t_map));
	if (!map_info)
		return (print_error(0), 0);
	map_info->map = return_map(argv[1]);
	if (!validate_map(&map_info, map_info->map))
	{
		free(map_info);
		return (free_map(map_info->map), 1);
	}
	xpm_to_img(map_info);
	render_map(map_info);
	map_info->move_count = 0;
	mlx_hook(map_info->window, 17, 1L >> 0, close_window, map_info);
	mlx_hook(map_info->window, 2, 1L >> 0, key_hook, map_info);
	mlx_loop(map_info->mlx);
}
