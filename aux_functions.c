/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 19:26:57 by momil-vo          #+#    #+#             */
/*   Updated: 2024/06/06 21:10:58 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// converts the program's parameters into a t_fractal_id for later use
t_fractal_id	ft_get_fractal_id(int argc, char **argv)
{
	t_fractal_id	ret;

	ret.c_im = 0;
	ret.c_re = 0;
	if (ft_strncmp(argv[1], "Julia", 5) == 0 && argc == 4)
	{
		ret.fractal_type = JULIA;
		ret.c_re = ft_atold(argv[2]);
		ret.c_im = REAL_AXIS_DIR * ft_atold(argv[3]);
		if (isnan(ret.c_re) || isnan(ret.c_im))
			ret.fractal_type = INVALID_FRACTAL;
	}
	else if (argc == 4)
		ret.fractal_type = INVALID_FRACTAL;
	else if (ft_strncmp(argv[1], "Mandelbrot", 10) == 0)
		ret.fractal_type = MANDELBROT;
	else if (ft_strncmp(argv[1], "Burningship", 11) == 0)
		ret.fractal_type = BURN_SHIP;
	else
		ret.fractal_type = INVALID_FRACTAL;
	ret.scape_radius = ft_scape_radius(ret);
	return (ret);
}

/*this funtion is called when the params of the program are invalid
it prints relevant information and returns 0*/
int	ft_input_error(int fractal_type)
{
	if (fractal_type == INVALID_FRACTAL)
		ft_printf(INPUT_ERROR_MSG);
	return (0);
}

/*converts a string with a decimal number into a long double
takes only positive values*/
long double	ft_atold_positives(char *str)
{
	long double	ret;
	int8_t		past_point;
	size_t		pos;
	long double	divisor;

	divisor = 1.0;
	pos = 0;
	past_point = 0;
	ret = 0.0;
	while (str[pos] != '\0')
	{
		if (str[pos] == '.' && past_point == 0)
			past_point = 1;
		else if ((str[pos] == '.' && past_point == 1) || !ft_isdigit(str[pos]))
			return (NAN);
		else if (past_point)
		{
			divisor = divisor * 10;
			ret = ret + (str[pos] - '0') / divisor;
		}
		else
			ret = ret * 10 + (str[pos] - '0');
		pos++;
	}
	return (ret);
}

/*converts a string with a decimal number into a long double*/
long double	ft_atold(char *str)
{
	while (*str == ' ')
		str++;
	if (*str == '\0')
		return (NAN);
	else if (*str == '-' && *(str + 1) == '\0')
		return (NAN);
	else if (*str == '-')
		return (-1 * ft_atold_positives(str + 1));
	return (ft_atold_positives(str++));
}
