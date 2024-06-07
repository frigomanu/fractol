/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_longhex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:03:31 by momil-vo          #+#    #+#             */
/*   Updated: 2024/01/30 14:13:36 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_char_to_digit_longhex(int n)
{
	if (n <= 9)
		return ('0' + n);
	else
		return ('a' + n - 10);
}

char	*ft_print_positive_longhex(unsigned long n, char *dest, int num_digits)
{
	int	pos;

	pos = 0;
	while (pos < num_digits)
	{
		dest[num_digits - pos - 1] = ft_char_to_digit_longhex(n % 16);
		n = n / 16;
		pos++;
	}
	dest[num_digits] = '\0';
	return (dest);
}

int	ft_num_digits_longhex(unsigned long n)
{
	int	num_digits;

	num_digits = 1;
	while (n >= 16)
	{
		num_digits++;
		n = n / 16;
	}
	return (num_digits);
}

char	*ft_itoa_longhex(unsigned long n, int num_digits)
{
	char	*ret;

	ret = ft_calloc((size_t)(num_digits + 1), sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_print_positive_longhex(n, ret, num_digits);
	return (ret);
}

t_num	ft_get_nbr_longhex(unsigned long num)
{
	t_num	ret;

	if (num == 0)
	{
		ret.n_digits = 1;
		ret.str = ft_strdup("0");
	}
	else if (num == (unsigned long) - 1)
	{
		ret.n_digits = 16;
		ret.str = ft_strdup("ffffffffffffffff");
	}
	else
	{
		ret.n_digits = ft_num_digits_longhex(num);
		ret.str = ft_itoa_longhex(num, ret.n_digits);
	}
	return (ret);
}
