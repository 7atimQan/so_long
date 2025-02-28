/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:22:22 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 18:08:06 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
// #include <stdio.h>

// int main ()
// {
// 	const char s1[] = "1234";
// 	const char s2[] = "1235";
// 	if (ft_strncmp(s1, s2, 3 * sizeof(int)) > 0)
// 		printf ("s1 > s2\n");
// 	else if(ft_strncmp(s1, s2, 3 * sizeof(int)) < 0)
// 		printf ("s2 > s1\n");
// 	else
// 		printf ("s2 = s1\n");
// }