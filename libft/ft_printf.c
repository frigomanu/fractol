/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:20:30 by momil-vo          #+#    #+#             */
/*   Updated: 2024/01/30 13:58:21 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_array(t_str s, va_list args);
int		ft_print_with_conversion(char c, va_list args);

int	ft_printf(char const *s_format, ...)
{
	int		ret;
	va_list	args;
	t_str	s;

	va_start(args, s_format);
	s.content = s_format;
	s.len = ft_strlen(s_format);
	s.pos = 0;
	ret = ft_print_array(s, args);
	va_end(args);
	return (ret);
}

int	ft_print_array(t_str s, va_list args)
{
	int	ret;

	ret = 0;
	while (s.pos < s.len)
	{
		if (s.content[s.pos] != '%')
		{
			ft_putchar_fd(s.content[s.pos], 1);
			ret++;
		}
		else
		{
			if (s.content[s.pos + 1] == ' ')
				ft_putchar_fd(' ', 1);
			while (s.content[s.pos + 1] == ' ')
			{
				s.pos++;
				ret++;
			}
			ret += ft_print_with_conversion(s.content[s.pos + 1], args);
			s.pos++;
		}
		s.pos++;
	}
	return (ret);
}

int	ft_print_with_conversion(char c, va_list args)
{
	if (c == '%')
		return (ft_write_c('%'));
	else if (c == 'c')
		return (ft_write_c(va_arg(args, int)));
	else if (c == 's')
		return (ft_write_s(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_write_p(va_arg(args, unsigned long)));
	else if (ft_strchr("diuxX", c) != NULL)
		return (ft_write_int(va_arg(args, int), c));
	return (0);
}
