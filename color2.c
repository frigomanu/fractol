/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:30:17 by momil-vo          #+#    #+#             */
/*   Updated: 2024/04/24 19:35:24 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint32_t	ft_count_z_to_color(int count, t_complex z,
								uint32_t color_a, uint32_t color_b)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	int		mode;

	mode = (count / 3) % 5;
	r = ft_get_r(color_a) + ((2 * mode + fmod(fabs(z.im), 15.0)) / 25.0)
		* (ft_get_r(color_b) - ft_get_r(color_a));
	g = ft_get_g(color_a) + ((fmod(fabs(z.re), 25.0)) / 25.0)
		* (ft_get_g(color_b) - ft_get_g(color_a));
	b = ft_get_b(color_a) + ((fmod(fabs(z.re) + fabs(z.re), 50.0))
			/ 50.0) * (ft_get_b(color_b) - ft_get_r(color_a));
	return (ft_trgb_to_color(0, r, g, b));
}

//generates a color depending on how long it took for the squence to scape
uint32_t	ft_z_to_color(t_complex z, uint32_t color_a, uint32_t color_b)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = ft_get_r(color_a) + (fmin(fabs(z.im), 5) / 5.0)
		* (ft_get_r(color_b) - ft_get_r(color_a));
	g = ft_get_g(color_a) + (fmin(fabs(z.re), 5) / 5.0)
		* (ft_get_g(color_b) - ft_get_g(color_a));
	b = ft_get_b(color_a) + (fmin(fabs(z.re) + fabs(z.re), 10) / 10.0)
		* (ft_get_b(color_b) - ft_get_r(color_a));
	return (ft_trgb_to_color(0, r, g, b));
}

//generates a color depending on how long it took for the squence to scape
uint32_t	ft_count_to_color(int count, int max_iter,
								uint32_t color_a, uint32_t color_b)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;

	r = ft_get_r(color_a) + (count / max_iter)
		* (ft_get_r(color_b) - ft_get_r(color_a));
	g = ft_get_g(color_a) + (count / max_iter)
		* (ft_get_g(color_b) - ft_get_g(color_a));
	b = ft_get_b(color_a) + (count / max_iter)
		* (ft_get_b(color_b) - ft_get_r(color_a));
	return (ft_trgb_to_color(0, r, g, b));
}

//gets the appropriate color correspontding to a complex number
// in accordance with the fractal being drawn
uint32_t	ft_get_color(t_render_data rdr, t_complex z)
{
	t_fractal_id	fractal;
	t_complex		c;
	unsigned int	count;

	fractal = rdr.fractal_id;
	count = 0;
	c = ft_build_complex(z.re, z.im);
	if (fractal.fractal_type == JULIA)
		c = ft_build_complex(fractal.c_re, fractal.c_im);
	while (count < rdr.max_iter && ft_in_bounds(fractal, z, 0))
	{
		z = ft_fractal_opperation(fractal.fractal_type, z, c);
		count++;
	}
	if (ft_square_modulo(z) < fractal.scape_radius + __FLT_EPSILON__)
		return (IN_COLOR);
	if (COLOR_ALGTHM == 0)
		return (ft_count_to_color(count, rdr.max_iter,
				OUT_COLOR_A, OUT_COLOR_B));
	else if (COLOR_ALGTHM == 1)
		return (ft_z_to_color(z, OUT_COLOR_A, OUT_COLOR_B));
	else
		return (ft_count_z_to_color(count, z, OUT_COLOR_A, OUT_COLOR_B));
}
