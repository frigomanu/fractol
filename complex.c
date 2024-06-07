/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:31:27 by momil-vo          #+#    #+#             */
/*   Updated: 2024/06/06 21:01:32 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_in_bounds(t_fractal_id fractal, t_complex z, int quick)
{
	float	max;

	if (quick)
	{
		max = fabs(z.im) + fabs(z.re);
		return (max < 2 * fractal.scape_radius);
	}
	return (ft_square_modulo(z) < fractal.scape_radius * fractal.scape_radius);
}

float	ft_scape_radius(t_fractal_id fractal)
{
	float	ret;
	float	c_squared;

	ret = fmax(DF_RADIUS, 2.0);
	if (fractal.fractal_type == MANDELBROT
		|| fractal.fractal_type == BURN_SHIP)
		return (ret);
	else if (fractal.fractal_type == JULIA)
	{
		c_squared = ft_square_modulo(
				ft_build_complex(fractal.c_re, fractal.c_im));
		while ((ret * (ret - 1)) * (ret * (ret - 1)) < c_squared)
			ret *= ret;
	}
	return (ret);
}

// returns |z|², where z is a complex value
double	ft_square_modulo(t_complex z)
{
	return (z.re * z.re + z.im * z.im);
}

//computes an iteration of the sequence corresponding to the appropiate fractal
t_complex	ft_fractal_opperation(int fractal_type, t_complex z, t_complex c)
{
	t_complex	ret;

	ret.re = 0;
	ret.im = 0;
	if (fractal_type == JULIA || fractal_type == MANDELBROT)
	{
		ret.re = z.re * z.re - z.im * z.im + c.re;
		ret.im = 2 * z.re * z.im + c.im;
	}
	else if (fractal_type == BURN_SHIP)
	{
		ret.re = z.re * z.re - z.im * z.im + c.re;
		if (ret.re < 0.0)
			ret.re = -ret.re;
		ret.im = 2 * z.re * z.im - c.im;
		if (ret.im < 0.0)
			ret.im = -ret.im;
	}
	return (ret);
}

t_complex	ft_build_complex(double long re, double long im)
{
	t_complex	ret;

	ret.re = re;
	ret.im = im;
	return (ret);
}
