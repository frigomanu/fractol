/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:50:04 by momil-vo          #+#    #+#             */
/*   Updated: 2023/09/18 22:45:10 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t num)
{
	unsigned char	*new_ptr;

	new_ptr = ptr;
	while (num > 0)
	{
		*new_ptr = (unsigned char) c;
		new_ptr++;
		num--;
	}
	return (ptr);
}
