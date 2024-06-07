/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usr_pantoxo <usr_pantoxo@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 23:42:08 by momil-vo          #+#    #+#             */
/*   Updated: 2024/04/13 23:13:15 by usr_pantoxo      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft.h"
# include <stdio.h>

typedef struct s_str
{
	const char	*content;
	int			len;
	int			pos;
}				t_str;

typedef struct s_num
{
	const char	*str;
	int			n_digits;
}				t_num;

int		ft_printf(char const *str, ...);
t_num	ft_get_nbr_dec(int num);
t_num	ft_get_nbr_uns(unsigned int num);
t_num	ft_get_nbr_hex(unsigned int num, int caps);
t_num	ft_get_nbr_longhex(unsigned long num);
int		ft_write_c(char c);
int		ft_write_s(char *str);
int		ft_write_int(int num, char c);
int		ft_write_p(long num);
int		ft_write_i_d(int num);
int		ft_write_x(int num, int caps);
int		ft_write_u(int num);

#endif
