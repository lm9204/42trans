/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:23:48 by yeondcho          #+#    #+#             */
/*   Updated: 2023/11/30 19:43:17 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *arg, ...);
int		read_format(const char *arg, va_list *va_arg);
void	print_format(char c, va_list *va_arg, int *totallen);
void	print_normal(const char *arg, int len, int *totallen);
int		pr_num(va_list *args);
int		pr_uns(va_list *args);
int		pr_addr(va_list *args, const char *hex);
int		pr_hex(va_list *args, const char *hex);
int		pr_str(va_list *args);
int		pr_char(va_list *args);

#endif