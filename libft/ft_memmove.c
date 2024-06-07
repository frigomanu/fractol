/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:50:04 by momil-vo          #+#    #+#             */
/*   Updated: 2023/10/10 01:19:20 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_move_right_to_left(void *dest, const void *srce, size_t num);
void	ft_move_left_to_right(void *dest, const void *srce, size_t num);

void	*ft_memmove(void *dest, const void *srce, size_t num)
{
	if ((srce == NULL && dest == NULL) || num == 0)
		return (dest);
	if (dest > srce)
		ft_move_right_to_left(dest, srce, num);
	else
		ft_move_left_to_right(dest, srce, num);
	return (dest);
}

void	ft_move_left_to_right(void *dest, const void *srce, size_t num)
{
	const unsigned char	*new_srce;
	size_t				pos;

	new_srce = srce;
	pos = 0;
	while (pos < num)
	{
		ft_memset(dest + pos, new_srce[pos], 1);
		pos++;
	}
}

void	ft_move_right_to_left(void *dest, const void *srce, size_t num)
{
	const unsigned char	*new_srce;
	size_t				pos;

	new_srce = srce;
	pos = num;
	while (pos > 0)
	{
		ft_memset(dest + pos - 1, new_srce[pos - 1], 1);
		pos--;
	}
}
