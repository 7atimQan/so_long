/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 10:11:45 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/26 21:07:55 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

int	print_unsigned(unsigned int n)
{
	int		len;
	char	c;

	len = ft_len(n);
	if (n >= 10)
		print_unsigned(n / 10);
	c = n % 10 + 48;
	write (1, &c, 1);
	return (len);
}
// #include <stdio.h>

// int main()
// {
// 	printf(": %d\n", print_unsigned(-1231));
// 	printf(": %d\n", print_unsigned(-2147483648));
// 	printf(": %d\n", print_unsigned(3042));
// 	printf(": %d\n", print_unsigned(8));
// 	printf(": %d\n", print_unsigned(-9));
// 	printf(": %d\n", print_unsigned(-0));
// 	printf(": %d\n", print_unsigned(0));
// 	printf(": %d\n", print_unsigned(-1));
// }