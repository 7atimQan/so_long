/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:44:58 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/08 11:15:23 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	print_error(int n)
{
	write (2, "Error\n", 6);
	if (n == 0)
		write(2, "Empty map\n", 10);
	else if (n == 1)
		write(2, "Not rectangular\n", 16);
	else if (n == 2)
		write(2, "Not surrounded by walls\n", 24);
	else if (n == 3)
		write(2, "Incorrect elements\n", 19);
	else if (n == 4)
		write(2, "Invalid path\n", 13);
	else if (n == 5)
		write(2, "Not a \".ber\" file\n", 18);
	else if (n == 6)
		write(2, "File does not exist\n", 20);
}

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

void	find_elements(t_map **map_info, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				(*map_info)->player_x = j;
				(*map_info)->player_y = i;
			}
			if (map[i][j] == 'E')
			{
				(*map_info)->exit_x = j;
				(*map_info)->exit_y = i;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_map *info, char **map, int x, int y, char **visited)
{
	if (x < 0 || y < 0 || y >= info->height || x >= info->width)
		return ;
	if (map[y][x] == '1' || visited[y][x] == 'V')
		return ;
	visited[y][x] = 'V';
	flood_fill(info, map, x + 1, y, visited);
	flood_fill(info, map, x - 1, y, visited);
	flood_fill(info, map, x, y + 1, visited);
	flood_fill(info, map, x, y - 1, visited);
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
