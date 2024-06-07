/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:53:15 by momil-vo          #+#    #+#             */
/*   Updated: 2024/01/30 14:03:42 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_write_i_d(int num)
{
	t_num	aux;

	aux = ft_get_nbr_dec(num);
	write(1, aux.str, aux.n_digits);
	free((char *) aux.str);
	return (aux.n_digits);
}

int	ft_write_x(int num, int caps)
{
	t_num	aux;

	aux = ft_get_nbr_hex(num, caps);
	write(1, aux.str, aux.n_digits);
	free((char *) aux.str);
	return (aux.n_digits);
}

int	ft_write_u(int num)
{
	t_num	aux;

	aux = ft_get_nbr_uns(num);
	write(1, aux.str, aux.n_digits);
	free((char *) aux.str);
	return (aux.n_digits);
}

int	ft_write_p(long num)
{
	t_num	aux;

	ft_putstr_fd("0x", 1);
	aux = ft_get_nbr_longhex(num);
	write(1, aux.str, aux.n_digits);
	free((char *) aux.str);
	return (aux.n_digits + 2);
}
