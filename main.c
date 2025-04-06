/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:26:35 by hqannouc          #+#    #+#             */
/*   Updated: 2025/04/06 16:05:01 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**test;

	i = 0;
	if (argc == 1)
		return (0);
	test = return_map(argv[1]);
	if (!validate_map(test))
		return (free_map(test), 1);
	while (test[i] != NULL)
	{
		ft_printf("%s\n", test[i]);
		i++;
	}
	free_map(test);
}
