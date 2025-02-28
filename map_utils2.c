/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:08:50 by hqannouc          #+#    #+#             */
/*   Updated: 2025/02/28 11:30:22 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	**duplicate_map(char **map)
{
	int		i;
	int		rows;
	char	**new_map;

	rows = 0;
	while (map[rows])
		rows++;
	new_map = malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		return (NULL);
	for (i = 0; i < rows; i++)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			while (--i >= 0)
				free(new_map[i]);
			free(new_map);
			return (NULL);
		}
	}
	new_map[rows] = NULL;
	return (new_map);
}
