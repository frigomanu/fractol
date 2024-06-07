/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:21:05 by momil-vo          #+#    #+#             */
/*   Updated: 2024/04/24 17:17:00 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//gets called when ESC is pressed
int	ft_its_closing_time(t_mlx_data *mlx_data)
{
	if (mlx_data->win == NULL)
	{
		mlx_destroy_display(mlx_data->obj);
		return (0);
	}
	mlx_destroy_image(mlx_data->obj, mlx_data->img_data.img);
	mlx_clear_window(mlx_data->obj, mlx_data->win);
	mlx_destroy_window(mlx_data->obj, mlx_data->win);
	free(mlx_data->obj);
	exit(1);
	return (0);
}

//changes the rendering limits so as to zoom in or out
void	ft_zoom(t_render_data *render, float zoom)
{
	t_complex	middle;
	t_complex	extnsn;

	extnsn.re = (render->max_re - render->min_re) / 2;
	extnsn.im = (render->max_im - render->min_im) / 2;
	middle.re = render->min_re + extnsn.re;
	middle.im = render->min_im + extnsn.im;
	render->min_re = middle.re - (1 - zoom) * extnsn.re;
	render->min_im = middle.im - (1 - zoom) * extnsn.im;
	render->max_re = middle.re + (1 - zoom) * extnsn.re;
	render->max_im = middle.im + (1 - zoom) * extnsn.im;
}

//changes the rendering limits so as to move in the desired direction
void	ft_move(t_render_data *render, int dir)
{
	t_complex	extnsn;

	extnsn.re = (dir == DIR_L || dir == DIR_R)
		* (render->max_re - render->min_re) * MOVE_RATIO;
	extnsn.im = (dir == DIR_U || dir == DIR_D)
		* (render->max_im - render->min_im) * MOVE_RATIO;
	if (dir == DIR_L)
		extnsn.re = -extnsn.re;
	else if (dir == DIR_D)
		extnsn.im = -extnsn.im;
	render->min_re += extnsn.re;
	render->max_re += extnsn.re;
	render->min_im += extnsn.im;
	render->max_im += extnsn.im;
}

int	ft_key_hook_2(int keysym, t_program_data *all)
{
	t_mlx_data		*mlx;
	t_render_data	*render;

	mlx = &(all->mlx);
	render = &(all->render);
	if (keysym == XK_w)
		render->max_iter = (int) fmax(50, render->max_iter + 50);
	else if (keysym == XK_s)
		render->max_iter = (int) fmax(50, render->max_iter - 50);
	else
		return (0);
	ft_draw_fractal(mlx, *render);
	return (0);
}

//gets called every time a key is pressed
int	ft_key_hook(int keysym, t_program_data *all)
{
	t_mlx_data		*mlx;
	t_render_data	*render;

	mlx = &(all->mlx);
	render = &(all->render);
	if (keysym == XK_Escape)
		return (ft_its_closing_time(mlx));
	if (keysym == XK_plus)
		ft_zoom(render, ZOOM);
	else if (keysym == XK_minus)
		ft_zoom(render, -ZOOM);
	else if (keysym == XK_Right)
		ft_move(render, DIR_R);
	else if (keysym == XK_Left)
		ft_move(render, DIR_L);
	else if (keysym == XK_Up)
		ft_move(render, DIR_U);
	else if (keysym == XK_Down)
		ft_move(render, DIR_D);
	else
		return (ft_key_hook_2(keysym, all));
	ft_draw_fractal(mlx, *render);
	return (0);
}
