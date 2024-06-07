/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usr_pantoxo <usr_pantoxo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:14:08 by momil-vo          #+#    #+#             */
/*   Updated: 2024/04/13 22:05:59 by usr_pantoxo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_digit_in_pos(int n, int pos)
{
	int	divisor;

	if (pos == 0)
		return (n % 10);
	divisor = 10;
	while (pos > 1)
	{
		divisor = 10 * divisor;
		pos--;
	}
	return ((n / divisor) % 10);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	k;
	int	num_digits;

	if (n == (-2147483647 -1))
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
	}
	num_digits = ft_num_digits(n);
	k = num_digits - 1;
	while (k >= 0)
	{
		ft_putchar_fd('0' + ft_get_digit_in_pos(n, k), fd);
		k--;
	}
}
