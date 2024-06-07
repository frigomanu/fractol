/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_dec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 22:07:59 by momil-vo          #+#    #+#             */
/*   Updated: 2024/01/30 13:56:37 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_num	ft_get_nbr_dec(int num)
{
	t_num	ret;

	ret.str = ft_itoa(num);
	if (num >= 0)
		ret.n_digits = ft_num_digits(num);
	else if (num != -2147483648)
		ret.n_digits = ft_num_digits(-num) + 1;
	else
		ret.n_digits = 11;
	return (ret);
}
