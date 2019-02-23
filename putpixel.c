/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:21:01 by gperilla          #+#    #+#             */
/*   Updated: 2017/12/14 06:05:00 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	my_putpixel(t_env *env, int x, int y, int color)
{
	int		pos;
	int8_t	mask;

	if ((x >= 0 && x <= env->winx - 1) && (y >= 0 && y <= env->winy - 1))
	{
		pos = (y * env->s_l + x * 4);
		mask = color;
		env->pix[pos] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 1] = mask;
		color = color >> 8;
		mask = color;
		env->pix[pos + 2] = mask;
		env->pix[pos + 3] = 0x00;
	}
}
