/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 09:20:34 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/24 23:06:19 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(int n)
{
	int	i;

	i = 0;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	if (n < 0)
		return (i + 2);
	return (i + 1);
}

int	print_num(int n)
{
	int		len;
	char	c;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	len = ft_len(n);
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		print_num(n / 10);
	c = n % 10 + 48;
	write (1, &c, 1);
	return (len);
}
