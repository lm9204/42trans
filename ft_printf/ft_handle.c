/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:04:47 by yeondcho          #+#    #+#             */
/*   Updated: 2023/11/30 19:55:32 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pr_num(va_list *args)
{
	char	res[12];
	int		i;
	int		n;
	int		write_len;
	int		flag;

	flag = 0;
	n = va_arg(*args, int);
	i = 10;
	if (n < 0)
		flag = 1;
	if (n == 0)
		res[i--] = '0';
	while (n != 0)
	{
		if (n < 0)
			res[i--] = n % 10 * -1 + 48;
		else
			res[i--] = n % 10 + 48;
		n /= 10;
	}
	if (flag)
		res[i--] = '-';
	res[11] = 0;
	write_len = write(1, &res[i + 1], 10 - i);
	if (write_len == -1)
		return (-1);
	return (write_len);
}

int	pr_uns(va_list *args)
{
	char			res[12];
	unsigned int	n;
	unsigned int	i;
	int				write_len;

	i = 10;
	n = va_arg(*args, unsigned int);
	write_len = 0;
	if (n == 0)
		res[i--] = '0';
	while (n != 0)
	{
		res[i--] = n % 10 + 48;
		n /= 10;
	}
	res[11] = 0;
	write_len = write(1, &res[i + 1], 10 - i);
	if (write_len == -1)
		return (-1);
	return (write_len);
}

//type 0 : char, 1 : string
int	pr_str(va_list *args)
{
	char	*s;
	int		len;
	int		write_len;

	s = va_arg(*args, char *);
	write_len = 0;
	if (s == NULL)
	{
		write_len = write(1, "(null)", 6);
		if (write_len == -1)
			return (-1);
		return (write_len);
	}
	len = ft_strlen(s);
	write_len = write(1, s, len);
	if (write_len == -1)
		return (-1);
	return (write_len);
}

int	pr_hex(va_list *args, const char *_hex)
{
	char			res[12];
	unsigned int	n;
	int				i;
	int				write_len;

	n = va_arg(*args, unsigned int);
	i = 10;
	write_len = 0;
	if (n == 0)
		res[i--] = '0';
	while (n != 0)
	{
		res[i--] = _hex[n % 16];
		n /= 16;
	}
	res[11] = 0;
	write_len = write(1, &res[i + 1], 10 - i);
	if (write_len == -1)
		return (-1);
	return (write_len);
}

int	pr_addr(va_list *args, const char *_hex)
{
	const char			*flag = "0x";
	char				res[17];
	unsigned long long	n;
	int					i;
	int					write_len;

	i = 15;
	n = (unsigned long long)va_arg(*args, unsigned long long);
	if (n == 0)
		res[i--] = '0';
	while (n != 0)
	{
		res[i--] = _hex[n % 16];
		n /= 16;
	}
	res[16] = 0;
	write_len = 0;
	write_len = write(1, flag, 2);
	write_len += write(1, &res[i + 1], 15 - i);
	if (write_len != 15 - i + 2)
		return (-1);
	return (write_len);
}
