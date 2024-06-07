/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:23:05 by momil-vo          #+#    #+#             */
/*   Updated: 2024/04/24 13:20:29 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//gets a reasonable number of iterations to try
int	ft_max_iter(t_render_data rdr)
{
	int	ret;

	if (VARIABLE_NBR_ITER == 0)
		return (rdr.max_iter);
	ret = -10 + (int) 400 * exp(
			-fmax(rdr.max_re - rdr.min_re, rdr.max_im - rdr.min_im));
	if (ret > 800)
		return (800);
	if (ret < 100)
		return (100);
	return (ret);
}

//draws the fractal to mlx img object
void	ft_draw_in_adress(t_mlx_data *mlx_data, t_render_data rdr)
{
	unsigned int	x;
	unsigned int	y;
	char			*ptr;
	t_complex		z;
	t_complex		step;

	rdr.max_iter = ft_max_iter(rdr);
	z = ft_build_complex(rdr.min_re, rdr.max_im);
	step.re = (rdr.max_re - rdr.min_re) / rdr.n_clms;
	step.im = (rdr.max_im - rdr.min_im) / rdr.n_rows;
	y = 0;
	while (y < rdr.n_rows)
	{
		x = 0;
		while (x < rdr.n_clms)
		{
			ptr = mlx_data->img_data.adr + (y * mlx_data->img_data.line_length
					+ x * (mlx_data->img_data.bpp / 8));
			*(uint32_t *) ptr = ft_get_color(rdr, z);
			z.re += step.re;
			x++;
		}
		z = ft_build_complex(rdr.min_re, z.im - step.im);
		y++;
	}
}

//draws in an img and puts it in the window
void	ft_draw_fractal(t_mlx_data *mlx_data, t_render_data render_data)
{
	ft_draw_in_adress(mlx_data, render_data);
	mlx_put_image_to_window(mlx_data->obj, mlx_data->win,
		mlx_data->img_data.img, 0, 0);
}

// initializes render data with default parameters and makes the first draw
t_render_data	ft_draw_default_fractal(t_mlx_data *mlx_data,
										t_fractal_id fractal_id)
{
	t_render_data	render_data;

	render_data.fractal_id = fractal_id;
	render_data.max_re = DF_MAX_RE;
	render_data.min_re = DF_MIN_RE;
	render_data.max_im = DF_MAX_IM;
	render_data.min_im = DF_MIN_IM;
	render_data.max_iter = DF_NBR_ITER;
	render_data.n_clms = mlx_data->width;
	render_data.n_rows = mlx_data->height;
	ft_draw_fractal(mlx_data, render_data);
	return (render_data);
}
