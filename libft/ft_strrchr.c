/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 11:51:23 by momil-vo          #+#    #+#             */
/*   Updated: 2023/10/10 01:08:06 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	char	*ret;

	c = c % 256;
	if (c == '\0')
		return (str + ft_strlen(str));
	ret = NULL;
	str = ft_strchr(str, c);
	while (str != NULL)
	{
		ret = str;
		str = ft_strchr(str + 1, c);
	}
	return (ret);
}
