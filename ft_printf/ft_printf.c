/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:42:47 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/27 22:33:35 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, const char format)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += print_char(va_arg(args, int));
	else if (format == 's')
		count += print_string(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		count += print_num(va_arg(args, int));
	else if (format == 'u')
		count += print_unsigned(va_arg(args, unsigned int));
	else if (format == 'p')
		count += print_ptr(va_arg(args, void *));
	else if (format == 'x' || format == 'X')
		count += print_hexa(va_arg(args, int), format);
	else if (format == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(args, str);
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '\0')
				return (-1);
			count += ft_format(args, str[i]);
		}
		else
			count += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
