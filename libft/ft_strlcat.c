/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 22:50:04 by momil-vo          #+#    #+#             */
/*   Updated: 2023/10/10 01:11:35 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t num)
{
	unsigned int	len_src;
	unsigned int	len_dst;
	unsigned int	i;

	i = 0;
	len_src = (unsigned int) ft_strlen(src);
	len_dst = (unsigned int) ft_strlen(dst);
	if (num < 1)
		return (len_src);
	if (len_dst >= num)
		return (len_src + num);
	while (len_dst + i < num - 1 && *(src + i) != '\0')
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}
