/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:33:14 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/24 23:01:46 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_ptr(unsigned long n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count + 2);
}

static void	ft_put_adr(unsigned long n)
{
	char	c;

	if (n == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (n >= 16)
		ft_put_adr(n / 16);
	c = n % 16;
	if (c >= 0 && c <= 9)
		c = c + '0';
	else
		c = c + 87;
	write (1, &c, 1);
}

int	print_ptr(void *ptr)
{
	unsigned long	p;

	p = (unsigned long)ptr;
	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	ft_put_adr(p);
	return (ft_len_ptr(p));
}
// #include <stdio.h>

// int main()
// {
// 	int	e;
// 	int *p = &e;
// 	char *s;

// 	printf(" : %d\n", printf("%p", p));
// 	print_ptr(p);
// 	printf("\n");
// 	printf(" : %d\n", printf("%p", &e));
// 	print_ptr(&e);
// 	printf("\n");
// 	printf(" : %d\n", printf("%p", &s));
// 	print_ptr(&s);
// 	printf("\n");
// }