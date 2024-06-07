/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:53:15 by momil-vo          #+#    #+#             */
/*   Updated: 2024/01/30 14:03:24 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_int(int num, char c)
{
	if (c == 'i' || c == 'd')
		return (ft_write_i_d(num));
	else if (c == 'x' || c == 'X')
		return (ft_write_x(num, c == 'X'));
	else
		return (ft_write_u(num));
}

int	ft_write_s(char *str)
{
	int	ret;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ret = ft_strlen(str);
	write(1, str, ret);
	return (ret);
}

// maybe check if printable?
int	ft_write_c(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
