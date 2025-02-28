/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hqannouc <hqannouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:44:59 by hqannouc          #+#    #+#             */
/*   Updated: 2024/11/26 21:32:02 by hqannouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	print_char(int c);
int	print_string(char *str);
int	print_num(int n);
int	print_ptr(void *ptr);
int	print_hexa(unsigned int n, const char format);
int	print_unsigned(unsigned int n);
int	ft_printf(const char *str, ...);

#endif