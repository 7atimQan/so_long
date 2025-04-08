/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:26:35 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/08 16:23:45 by hqannouc         ###   ########.fr       */
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
	mlx_loop(map_info->mlx);
	close_window(map_info);
	// free(map_info);
	// free_map(map_info->map);
}
