/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 09:44:58 by hqannouc          #+#    #+#             */
/*   Updated: 2025/02/27 10:09:41 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		return (NULL);
	to_split = read_file_to_string(fd);
	close(fd);
	if (!to_split)
		return (NULL);
	map = ft_split(to_split, '\n');
	free(to_split);
	return (map);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
