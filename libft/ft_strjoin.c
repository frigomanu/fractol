/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:41:04 by momil-vo          #+#    #+#             */
/*   Updated: 2023/10/10 01:06:38 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*ret;

	len_s1 = (size_t) ft_strlen(s1);
	len_s2 = (size_t) ft_strlen(s2);
	if (len_s1 == 0 && len_s2 == 0)
		return (ft_calloc(1, sizeof(char)));
	ret = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s1, len_s1 + 1);
	ft_strlcat(ret, s2, len_s1 + len_s2 + 1);
	return (ret);
}
