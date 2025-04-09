/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:08:50 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/09 15:55:34 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ber_check(t_map *game, char *filename)
{
	char	*ext;
	char	*name;

	ext = ft_strrchr(filename, '.');
	name = ft_strrchr(filename, '/');
	if (!name)
	{
		if (ft_strlen(filename) > 4 && ft_strncmp(ext, ".ber", 4) == 0)
			return ;
	}
	else if (ext && ft_strlen(ext) == 4)
	{
		if (ft_strlen(name) > 5 && ft_strncmp(ext, ".ber", 4) == 0)
			return ;
	}
	error_exit(game, 5);
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
			get_next_line(-1);
			return (NULL);
		}
		temp = to_split;
		to_split = ft_strjoin(temp, line);
		free(temp);
		free(line);
		line = get_next_line(fd);
	}
	return (to_split);
}

char	**return_map(t_map *game, char *filename)
{
	int		fd;
	char	*to_split;
	char	**map;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_exit(game, 6);
	ber_check(game, filename);
	to_split = read_file_to_string(fd);
	close(fd);
	if (!to_split)
		error_exit(game, 0);
	map = ft_split(to_split, '\n');
	free(to_split);
	if (!map)
		return (NULL);
	return (map);
}

void	height_width(t_map **map_info, char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	(*map_info)->width = ft_strlen(map[0]);
	(*map_info)->height = i;
}

char	**duplicate_map(t_map *map_info, char **map)
{
	int		i;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (map_info->height + 1));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < map_info->height)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			return (NULL);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}
