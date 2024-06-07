/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:51:07 by momil-vo          #+#    #+#             */
/*   Updated: 2023/11/04 14:08:43 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **mem, int sz)
{
	while (sz >= 0)
	{
		free(mem[sz]);
		sz--;
	}
	free(mem);
	return (NULL);
}

int	ft_count_strings(char const *s, char c)
{
	int	ret;
	int	i;

	ret = s[0] != c;
	i = 0;
	if (s[0] != '\0')
	{
		while (s[i + 1] != '\0')
		{
			if (s[i] == c && s[i + 1] != c)
				ret++;
			i++;
		}
	}
	return (ret);
}

char	**ft_split_aux(char const *s, char c, int num, int i)
{
	char	**aux;
	int		k;
	char	*stop_pos;
	int		end;

	k = 0;
	end = 0;
	stop_pos = (char *) s;
	aux = ft_calloc((size_t) num + 1, sizeof(char *));
	while (s[k] == c)
		k++;
	while (! end && s[k] != '\0' && aux != NULL && i++ >= -1)
	{
		stop_pos = ft_strchr((char *) s + k, c);
		end = stop_pos == NULL;
		if (end)
			stop_pos = (char *) s + ft_strlen(s);
		aux[i] = ft_substr(s, (unsigned int) k, (size_t)(stop_pos - s) - k);
		if (aux[i] == NULL)
			return (ft_free(aux, i));
		k = (int)(stop_pos - s) + 1;
		while (! end && s[k] == c)
			k++;
	}
	return (aux);
}

char	**ft_split_positive_len(char const *s, char c, int num_occurrences)
{
	char	**ret;

	if (c == '\0')
	{
		ret = ft_calloc(2, sizeof(char *));
		if (ret == NULL)
			return (NULL);
		ret[0] = ft_strdup(s);
		if (ret[0] == NULL)
			return (ft_free(ret, 1));
	}
	else
		ret = ft_split_aux(s, c, num_occurrences, -1);
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	int		num_occurrences;

	if (ft_strlen(s) == 0)
		return (ft_calloc(1, sizeof(char *)));
	num_occurrences = ft_count_strings(s, c);
	if (num_occurrences == 0)
		return (ft_calloc(1, sizeof(char *)));
	else
		return (ft_split_positive_len(s, c, num_occurrences));
}
