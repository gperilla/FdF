/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 05:44:40 by gperilla          #+#    #+#             */
/*   Updated: 2017/12/21 17:52:37 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int		ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int		set_color(t_env *env, int x, int y)
{
	int color;

	color = 0x0000FF00;
	if (env->tmap->values[y][x] >= 0)
		color = color + (ft_min(1.0 * env->tmap->values[y][x], 15) * 0x00110000)
	- (ft_min(1.8 * env->tmap->values[y][x], 15) * 0x00001100);
	else
		color = color + (ft_max(1.2 * env->tmap->values[y][x], -15)
	* 0x00001100) - (ft_max(1.8 * env->tmap->values[y][x], -15) * 0x00000011);
	return (color);
}
