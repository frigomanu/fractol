/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:50:04 by momil-vo          #+#    #+#             */
/*   Updated: 2023/10/10 01:37:45 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t num)
{
	const unsigned char	*new_source;
	const unsigned char	*new_destination;
	size_t				pos;

	new_source = source;
	new_destination = destination;
	pos = 0;
	if (source == NULL || num == 0)
	{
		if (destination != NULL && *new_destination != '\0' && num > 0)
			raise(SIGSEGV);
		return (destination);
	}
	while (pos < num)
	{
		ft_memset(destination + pos, *(new_source + pos), 1);
		pos++;
	}
	return (destination);
}
