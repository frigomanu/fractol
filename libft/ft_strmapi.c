/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:49:50 by momil-vo          #+#    #+#             */
/*   Updated: 2023/10/10 01:07:54 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		len_s;
	int		k;

	len_s = ft_strlen(s);
	ret = ft_strdup(s);
	if (ret == NULL)
		return (NULL);
	k = 0;
	while (k < len_s)
	{
		ret[k] = f(k, ret[k]);
		k++;
	}
	return (ret);
}
