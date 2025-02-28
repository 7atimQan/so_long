/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 10:56:46 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 15:56:15 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*dup;

	i = 0;
	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	dup = (char *) malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
// #include <stdio.h>

// int main ()
// {
// 	char *s = "Bonjour, je m'appelle Hatim QANNOUCH";
// 	char *d = ft_strdup(s);
// 	printf("%s\n", d);
// }
