/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:03:06 by momil-vo          #+#    #+#             */
/*   Updated: 2023/10/10 01:05:57 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_print_positive(int n, char *dest, int num_digits)
{
	int	pos;

	pos = 0;
	while (pos < num_digits)
	{
		dest[num_digits - pos - 1] = '0' + n % 10;
		n = n / 10;
		pos++;
	}
	dest[num_digits] = '\0';
	return (dest);
}

int	ft_num_digits(int n)
{
	int	num_digits;

	num_digits = 1;
	while (n >= 10)
	{
		num_digits++;
		n = n / 10;
	}
	return (num_digits);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		num_digits;
	int		is_neg;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == (-2147483647 -1))
		return (ft_strdup("-2147483648"));
	is_neg = n < 0;
	if (is_neg)
		n = n * -1;
	num_digits = ft_num_digits(n);
	ret = ft_calloc((size_t)(num_digits + 1 + is_neg), sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[0] = '-';
	ft_print_positive(n, ret + is_neg, num_digits);
	return (ret);
}
