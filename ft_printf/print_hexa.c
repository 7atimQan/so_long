/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:43:46 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/26 21:17:11 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static char	ft_convert(char c, const char format)
{
	if (c >= 0 && c <= 9)
		c = c + '0';
	else if (format == 'x')
		c = c + 87;
	else if (format == 'X')
		c = c + 55;
	return (c);
}

int	print_hexa(unsigned int n, const char format)
{
	int		len;
	char	c;

	if (n == 0)
	{
		c = '0';
		write (1, &c, 1);
		return (1);
	}
	len = ft_len(n);
	if (n >= 16)
		print_hexa((n / 16), format);
	c = ft_convert((n % 16), format);
	write (1, &c, 1);
	return (len);
}
// #include <stdio.h>

// int main()
// {
// 	printf(": %d\n", print_hexa(-1231, 'x'));
// 	printf(": %d\n", print_hexa(-2147483648, 'x'));
// 	printf(": %d\n", print_hexa(3042, 'X'));
// 	printf(": %d\n", print_hexa(8, 'X'));
// 	printf(": %d\n", print_hexa(-9, 'X'));
// 	printf(": %x\n", print_hexa(9, 'X'));
// 	printf(": %d\n", print_hexa(-0, 'X'));
// 	printf(": %d\n", print_hexa(0, 'X'));
// 	printf(": %d\n", print_hexa(-1, 'x'));
// 	printf(": %d\n", print_hexa(15, 'X'));
// }