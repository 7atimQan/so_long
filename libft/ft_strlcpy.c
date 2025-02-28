/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 16:43:20 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 21:40:32 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t d_size)
{
	size_t	i;

	i = 0;
	if (d_size == 0)
		return (ft_strlen(src));
	while (i < d_size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
// #include <stdio.h>

// int main ()
// {
// 	char *s = "World cv ?";
// 	char d[10]= "Hello, ";
//printf("Length : %d, String : %s \n", ft_strlcpy(d, s, 12), d);
// }