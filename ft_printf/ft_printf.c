/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:22:53 by yeondcho          #+#    #+#             */
/*   Updated: 2023/11/30 19:51:09 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *arg, ...)
{
	va_list	va_args;
	int		res;
	int		len;

	va_start(va_args, arg);
	len = 0;
	res = read_format(arg, &va_args);
	if (res == -1)
		return (-1);
	va_end(va_args);
	return (res);
}

int	print_format(char c, va_list *va_arg)
{
	const char	*_hex_lower = "0123456789abcdef";
	const char	*_hex_upper = "0123456789ABCDEF";
	int			check;

	if (c == 'd' || c == 'i')
		return (pr_num(va_arg));
	if (c == 'u')
		return (pr_uns(va_arg));
	if (c == 's')
		return (pr_str(va_arg));
	if (c == 'c')
		return (pr_char(va_arg));
	if (c == 'x')
		return (pr_hex(va_arg, _hex_lower));
	if (c == 'X')
		return (pr_hex(va_arg, _hex_upper));
	if (c == 'p')
		return (pr_addr(va_arg, _hex_lower));
	if (c == '%')
	{
		check = write(1, "%", 1);
		if (check == -1)
			return (-1);
		return (check);
	}
	return (0);
}

int	read_format(const char *arg, va_list *va_arg)
{
	int		i;
	int		count;
	int		totallen;
	int		check_write;

	i = 0;
	count = 0;
	totallen = 0;
	while (arg[i])
	{
		if (arg[i] == '%')
		{
			if (i >= 1)
			{
				check_write = print_normal(&arg[i - count], count);
				if (check_write == -1)
					return (-1);
				totallen += check_write;
				count = 0;
			}
			check_write = print_format(arg[++i], va_arg);
			if (check_write == -1)
				return (-1);
			totallen += check_write;
		}
		else
			count++;
		i++;
	}
	if (i != 0 && count != 0)
	{
		check_write =  print_normal(&arg[i - count], count);
		if (check_write == -1)
			return (-1);
		totallen += check_write;
	}
	return (totallen);
}

int	print_normal(const char *arg, int len)
{
	int		write_len;

	write_len = write(1, arg, len);
	if (write_len == -1)
		return (-1);
	return (write_len);
}

int	pr_char(va_list *args)
{
	int		write_len;
	char	c;

	c = va_arg(*args, int);
	write_len = write(1, &c, 1);
	if (write_len == -1)
		return (-1);
	return (write_len);
}
