/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usr_pantoxo <usr_pantoxo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:34:32 by momil-vo          #+#    #+#             */
/*   Updated: 2024/04/13 22:09:26 by usr_pantoxo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_aux_in_str(char c, const char *set)
{
	int	pos;

	pos = 0;
	while (set[pos] != '\0')
	{
		if (set[pos] == c)
			return (1);
		pos++;
	}
	return (0);
}

int	ft_aux_pos_left(char const *s1, char const *set)
{
	int		pos_s1;
	int		ret;
	size_t	len_s1;

	len_s1 = (size_t) ft_strlen(s1);
	pos_s1 = 0;
	ret = -1;
	while (pos_s1 < (int) len_s1 && ret < 0)
	{
		if (!ft_aux_in_str(s1[pos_s1], set))
			ret = pos_s1;
		pos_s1++;
	}
	return (ret);
}

int	ft_aux_pos_right(char const *s1, char const *set)
{
	int		pos_s1;
	int		ret;
	size_t	len_s1;

	len_s1 = (size_t) ft_strlen(s1);
	pos_s1 = len_s1 - 1;
	ret = -1;
	while (pos_s1 >= 0 && ret < 0)
	{
		if (!ft_aux_in_str(s1[pos_s1], set))
			ret = pos_s1;
		pos_s1--;
	}
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		l;
	int		r;

	if (ft_strlen(s1) == 0)
		return (ft_calloc(1, sizeof(char)));
	l = ft_aux_pos_left(s1, set);
	r = ft_aux_pos_right(s1, set);
	ret = ft_calloc(r - l + 2, sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strlcpy(ret, s1 + l, r - l + 2);
	return (ret);
}

char	*ft_strtrim_char(char const *s1, char const c)
{
	char	*aux;
	char	*ret;

	aux = ft_calloc(2, sizeof(char));
	if (aux == NULL)
		return (NULL);
	aux[0] = c;
	ret = ft_strtrim(s1, aux);
	free(aux);
	return (ret);
}
