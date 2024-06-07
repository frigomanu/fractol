/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_uns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:03:06 by momil-vo          #+#    #+#             */
/*   Updated: 2024/01/30 13:57:49 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_print_positive_uns(unsigned int n, char *dest, int num_digits)
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

int	ft_num_digits_uns(unsigned int n)
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

char	*ft_itoa_uns(unsigned int n, int num_digits)
{
	char	*ret;

	if (n == 0)
		return (ft_strdup("0"));
	num_digits = ft_num_digits_uns(n);
	ret = ft_calloc((size_t)(num_digits + 1), sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_print_positive_uns(n, ret, num_digits);
	return (ret);
}

t_num	ft_get_nbr_uns(unsigned int num)
{
	t_num	ret;

	ret.n_digits = ft_num_digits_uns(num);
	ret.str = ft_itoa_uns(num, ret.n_digits);
	return (ret);
}
