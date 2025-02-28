/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:44:58 by hqannouc          #+#    #+#             */
/*   Updated: 2025/02/28 12:32:09 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	*x = -1;
	*y = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				ft_printf("Player found at (%d, %d)\n", *x, *y);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(char **map, int x, int y, char **visited)
{
	int	height;
	int	width;

	height = 0;
	while (map[height])
		height++;
	width = ft_strlen(map[0]);
	if (x < 0 || y < 0 || y >= height || x >= width)
		return ;
	if (map[y][x] == '1' || visited[y][x] == 'V')
		return ;
	visited[y][x] = 'V';
	flood_fill(map, x + 1, y, visited);
	flood_fill(map, x - 1, y, visited);
	flood_fill(map, x, y + 1, visited);
	flood_fill(map, x, y - 1, visited);
}

int	check_valid_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
			if (map[i][j] == 'V')
				map[i][j] = '0';
			j++;
		}
		i++;
	}
	return (1);
}
