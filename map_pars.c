/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:01:10 by hqannouc          #+#    #+#             */
/*   Updated: 2025/02/28 10:51:00 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_check(char *filename)
{
	char	*ext;

	printf("%s : ", filename);
	ext = ft_strrchr(filename, '.');
	if (ext && ft_strlen(ext) == 4)
	{
		if (ft_strlen(filename) > 4 && ft_strncmp(ext, ".ber", 4) == 0)
			return (1);
	}
	return (0);
}

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
			return (0);
		i++;
	}
	return (1);
}

int	check_walls(char **map)
{
	int	i;
	int	last_column;
	int	last_row;

	if (!map || !map[0])
		return (0);
	last_row = 0;
	while (map[last_row + 1])
		last_row++;
	i = 0;
	last_column = ft_strlen(map[0]) - 1;
	while (i <= last_column)
	{
		if (map[0][i] != '1' || map[last_row][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][last_column] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	has_elements(char **map)
{
	int	e;
	int	c;
	int	p;
	int	i;
	int	j;

	(1) & (e = 0, c = 0, p = 0, i = 0);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (e == 1 && c >= 1 && p == 1)
		return (1);
	return (0);
}

int	validate_map(char **map)
{
	
}
int	main(void)
{
	int		i;
	char	**test;

	i = 0;
	test = return_map("file1.ber");
	if (test && is_rectangular(test) && check_walls(test) && has_elements(test))
	{
		ft_printf("Map is valid \n\n");
		while (test[i] != NULL)
		{
			ft_printf("%s\n", test[i]);
			i++;
		}
	}
	else
		ft_printf("Invalid Map\n");
	free_map(test);
	return (0);
}
