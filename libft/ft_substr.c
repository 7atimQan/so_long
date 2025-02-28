/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:42:13 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 20:14:01 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*sub;

	if (str == NULL)
		return (NULL);
	str_len = 0;
	i = 0;
	while (str[str_len] != '\0')
		str_len++;
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len && str[start] != '\0')
		sub[i++] = str[start++];
	sub[i] = '\0';
	return (sub);
}
// #include <stdio.h>

// int main()
// {
// 	printf("%s\n", ft_substr("Na3ima sami7", 15, 8));
// }
