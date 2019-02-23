/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:19:45 by gperilla          #+#    #+#             */
/*   Updated: 2017/12/14 08:55:44 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

static void		unsens(t_env *env, t_line ln, int color)
{
	int i;

	my_putpixel(env, ln.x, ln.y, color);
	i = 1;
	ln.p = ln.dx / 2;
	while (i <= ln.dx)
	{
		ln.x += ln.xdir;
		ln.p += ln.dy;
		if (ln.p >= ln.dx)
		{
			ln.p -= ln.dx;
			ln.y += ln.ydir;
		}
		my_putpixel(env, ln.x, ln.y, color);
		++i;
	}
}

static void		lautsens(t_env *env, t_line ln, int color)
{
	int i;

	my_putpixel(env, ln.x, ln.y, color);
	i = 1;
	ln.p = ln.dy / 2;
	while (i <= ln.dy)
	{
		ln.y += ln.ydir;
		ln.p += ln.dx;
		if (ln.p >= ln.dy)
		{
			ln.p -= ln.dy;
			ln.x += ln.xdir;
		}
		my_putpixel(env, ln.x, ln.y, color);
		++i;
	}
}

void			draw_line(t_env *env, t_point *pt1, t_point *pt2, int color)
{
	t_line	ln;

	ln.dx = (pt2->x) - (pt1->x);
	ln.dy = (pt2->y) - (pt1->y);
	ln.x = (pt1->x);
	ln.y = (pt1->y);
	ln.xdir = (ln.dx > 0) ? 1 : -1;
	ln.ydir = (ln.dy > 0) ? 1 : -1;
	ln.dx = ft_abs(ln.dx);
	ln.dy = ft_abs(ln.dy);
	if (ln.dx > ln.dy)
		unsens(env, ln, color);
	else
		lautsens(env, ln, color);
}
