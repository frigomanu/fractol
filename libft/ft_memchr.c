/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 20:45:46 by momil-vo          #+#    #+#             */
/*   Updated: 2023/10/10 01:59:30 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*ret;
	size_t			k;

	if (n == 0)
		return (NULL);
	ret = (unsigned char *) str;
	k = 0;
	while (ret[k] != (unsigned char) c)
	{
		if (k == n - 1)
			return (NULL);
		k++;
	}
	return ((void *) ret + k);
}
