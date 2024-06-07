/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 20:03:31 by momil-vo          #+#    #+#             */
/*   Updated: 2024/01/30 14:13:00 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_char_to_digit_hex(int n, int caps)
{
	if (n <= 9)
		return ('0' + n);
	else if (caps)
		return ('A' + n - 10);
	else
		return ('a' + n - 10);
}

char	*ft_print_positive_hex(unsigned int n, char *dest,
								int num_digits, int caps)
{
	int	pos;

	pos = 0;
	while (pos < num_digits)
	{
		dest[num_digits - pos - 1] = ft_char_to_digit_hex(n % 16, caps);
		n = n / 16;
		pos++;
	}
	dest[num_digits] = '\0';
	return (dest);
}

int	ft_num_digits_hex(unsigned int n)
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

char	*ft_itoa_hex(unsigned int n, int num_digits, int caps)
{
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == (unsigned int) - 1)
	{
		if (caps)
			return (ft_strdup("FFFFFFFFFFFFFFFF"));
		else
			return (ft_strdup("ffffffffffffffff"));
	}
	num_digits = ft_num_digits_hex(n);
	ret = ft_calloc((size_t)(num_digits + 1), sizeof(char));
	if (ret == NULL)
		return (NULL);
	ret[0] = '-';
	ft_print_positive_hex(n, ret, num_digits, caps);
	return (ret);
}

t_num	ft_get_nbr_hex(unsigned int num, int caps)
{
	t_num	ret;

	ret.n_digits = ft_num_digits_hex(num);
	ret.str = ft_itoa_hex(num, ret.n_digits, caps);
	return (ret);
}
