/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:01:10 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/06 16:36:28 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_rectangular(char **map)
{
	int		i;
	size_t	len;

	if (!map || !map[0])
		return (0);
	len = ft_strlen(map[0]);
	i = 0;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[i]) != len || map[i][0] == '\n')
			return (print_error(1), 0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	last_column;
	int	last_row;

	last_row = 0;
	while (map[last_row + 1])
		last_row++;
	i = 0;
	last_column = ft_strlen(map[0]) - 1;
	while (i <= last_column)
	{
		if (map[0][i] != '1' || map[last_row][i] != '1')
			return (print_error(2), 0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][last_column] != '1')
			return (print_error(2), 0);
		i++;
	}
	return (1);
}

int	foreign_elements(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'E' && map[i][j] != 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_elements(char **map)
{
	int	e;
	int	c;
	int	p;
	int	j;
	int	i;

	e = 0;
	c = 0;
	p = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P')
				p++;
			else if (map[i][j] == 'E')
				e++;
			else if (map[i][j] == 'C')
				c++;
		}
	}
	return (e == 1 && c >= 1 && p == 1);
}

int	validate_map(char **map)
{
	int		x;
	int		y;
	char	**visited;

	if (!map || !map[0])
		return (print_error(0), 0);
	if (!is_rectangular(map) || !check_walls(map))
		return (0);
	if (!has_elements(map) || !foreign_elements(map))
		return (print_error(3), 0);
	find_player(map, &x, &y);
	visited = duplicate_map(map);
	if (!visited)
		return (0);
	flood_fill(map, x, y, visited);
	if (!check_valid_path(visited))
	{
		free_map(visited);
		return (print_error(4), 0);
	}
	free_map(visited);
	return (1);
}
