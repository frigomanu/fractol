/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momil-vo <momil-vo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:30:17 by momil-vo          #+#    #+#             */
/*   Updated: 2024/04/23 16:45:54 by momil-vo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

uint8_t	ft_get_t(uint32_t trgb)
{
	return (trgb >> 24);
}

uint8_t	ft_get_r(uint32_t trgb)
{
	return (trgb >> 16);
}

uint8_t	ft_get_g(uint32_t trgb)
{
	return (trgb >> 8);
}

uint8_t	ft_get_b(uint32_t trgb)
{
	return (trgb);
}

uint32_t	ft_trgb_to_color(uint8_t t, uint8_t r, uint8_t g, uint8_t b)
{
	return ((t << 24) + (r << 16) + (g << 8) + b);
}
