/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:56:41 by momil-vo          #+#    #+#             */
/*   Updated: 2023/10/10 01:08:03 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *sml, size_t len)
{
	int		max_pos;
	size_t	len_sml;
	size_t	len_big;
	size_t	i;

	len_sml = (size_t) ft_strlen(sml);
	len_big = (size_t) ft_strlen(big);
	if (*sml == '\0')
		return ((char *) big);
	if (len <= 0 || len_sml > len_big)
		return (NULL);
	if ((size_t) len_big < len)
		len = len_big;
	max_pos = len - len_sml;
	if (max_pos < 0)
		return (NULL);
	i = 0;
	while (i <= (size_t) max_pos)
	{
		if (ft_strncmp(big + i, sml, len_sml) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
