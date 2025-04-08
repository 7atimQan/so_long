/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:26:35 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/08 12:06:45 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**test;
	t_map	*map_info;

	if (argc == 1)
		return (0);
	map_info = malloc(sizeof(t_map));
	if (!map_info)
		return (print_error(0), 0);
	test = return_map(argv[1]);
	if (!validate_map(&map_info, test))
	{
		free(map_info);
		return (free_map(test), 1);
	}
	xpm_to_img(map_info);
	free(map_info);
	free_map(test);
}
