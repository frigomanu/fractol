/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:27:41 by momil-vo          #+#    #+#             */
/*   Updated: 2024/04/08 19:33:04 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*ret;
	size_t			num;

	ret = malloc(nitems * size);
	if (ret == NULL)
		return (NULL);
	num = 0;
	while (num < nitems * size)
	{
		ret[num] = (unsigned char) '\0';
		num++;
	}
	return ((void *)ret);
}
