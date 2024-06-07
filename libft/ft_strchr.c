/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:03:58 by momil-vo          #+#    #+#             */
/*   Updated: 2024/04/18 22:01:26 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *str, int c)
{
	char	*ret;

	if (c == '\0')
		return (str + ft_strlen(str));
	if (c > 255)
		c = c % 256;
	if (!(ft_isascii(c)))
		return (str);
	ret = str;
	while (*ret != c)
	{
		if (*ret == '\0')
			return (NULL);
		ret++;
	}
	return (ret);
}
