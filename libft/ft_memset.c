/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 12:31:47 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/17 21:41:48 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	unsigned char	byte_value;
	size_t			i;

	p = (unsigned char *)ptr;
	byte_value = (unsigned char)value;
	i = 0;
	while (i < num)
	{
		p[i] = byte_value;
		i++;
	}
	return (ptr);
}
// #include <stdio.h>
// int main()
// {
//     int i = 0;
//     int s[] = {1, 2, 2, 5, 42, 5};
//     // Using ft_memset to set the first 5 bytes to 6
//     ft_memset(s, 6, 5 * sizeof(int));
//     while (i < 6)
//     {
//         printf("%d\n", s[i]);
//         i++;
//     }
//     return (0);
// }