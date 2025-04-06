/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:08:50 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/06 16:22:24 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ber_check(char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (ext && ft_strlen(ext) == 4)
	{
		if (ft_strlen(filename) > 4 && ft_strncmp(ext, ".ber", 4) == 0)
			return (1);
	}
	print_error(5);
	exit(1);
}

char	*read_file_to_string(int fd)
{
	char	*line;
	char	*temp;
	char	*to_split;

	to_split = ft_strdup("");
	if (!to_split)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) == 1 && line[0] == '\n')
		{
			free(line);
			free(to_split);
			return (NULL);
		}
		temp = to_split;
		to_split = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (to_split);
}

char	**return_map(char *filename)
{
	int		fd;
	char	*to_split;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error(6);
		exit(1);
	}
	if (!ber_check(filename))
		return (NULL);
	to_split = read_file_to_string(fd);
	close(fd);
	if (!to_split)
		return (NULL);
	map = ft_split(to_split, '\n');
	free(to_split);
	if (!map)
		return (NULL);
	return (map);
}

char	**duplicate_map(char **map)
{
	int		rows;
	int		i;
	char	**new_map;

	rows = 0;
	while (map[rows])
		rows++;
	new_map = malloc(sizeof(char *) * (rows + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
		}
		i++;
	}
	new_map[rows] = NULL;
	return (new_map);
}
