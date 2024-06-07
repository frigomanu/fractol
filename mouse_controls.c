/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:53:05 by momil-vo          #+#    #+#             */
/*   Updated: 2024/04/24 19:35:13 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//
int	ft_expose_hook(t_program_data *all)
{
	t_mlx_data	mlx;

	mlx = all->mlx;
	mlx_put_image_to_window(mlx.obj, mlx.win,
		mlx.img_data.img, 0, 0);
	return (0);
}

//changes the rendering limits so as to zoom in or out
void	ft_zoom_middle(t_render_data *render, float zoom,
						t_complex middle, t_complex extnsn)
{
	extnsn.re = extnsn.re / 2;
	extnsn.im = extnsn.im / 2;
	render->min_re = middle.re - (1 - zoom) * extnsn.re;
	render->max_re = middle.re + (1 - zoom) * extnsn.re;
	render->min_im = middle.im - (1 - zoom) * extnsn.im;
	render->max_im = middle.im + (1 - zoom) * extnsn.im;
}

//
int	ft_mouse_hook(int button, int x, int y, t_program_data *all)
{
	t_mlx_data		*mlx;
	t_render_data	*render;
	t_complex		middle;
	t_complex		extnsn;

	mlx = &(all->mlx);
	render = &(all->render);
	x = x * ZOOM + mlx->width * (1 - ZOOM) / 2;
	y = y * ZOOM + mlx->height * (1 - ZOOM) / 2;
	mlx_pixel_put(mlx->obj, mlx->win, x, y, 0xFFFFFF);
	extnsn.re = (render->max_re - render->min_re);
	extnsn.im = (render->max_im - render->min_im);
	middle.re = render->min_re + (extnsn.re * x / render->n_clms);
	middle.im = render->max_im - (extnsn.im * y / render->n_rows);
	if (button == L_CLICK)
		ft_zoom_middle(render, +ZOOM, middle, extnsn);
	else if (button == R_CLICK)
		ft_zoom_middle(render, -ZOOM, middle, extnsn);
	else if (button == SCROL_D)
		ft_zoom_middle(render, +ZOOM, middle, extnsn);
	else if (button == SCROL_U)
		ft_zoom_middle(render, -ZOOM, middle, extnsn);
	ft_draw_fractal(mlx, *render);
	return (0);
}
