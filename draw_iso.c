/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_iso.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 21:59:13 by gperilla          #+#    #+#             */
/*   Updated: 2017/12/14 09:50:59 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include <stdlib.h>

static void		horizontal(t_env *env, t_point a, int x, int y)
{
	t_point b;
	int		color;

	b.x = (((env->tmap->sizey - y) + x + 1) * (env->winx / (env->tmap->sizey
		+ env->tmap->sizex))) * env->zoom + env->dx;
	b.y = ((x + y + 2) * (env->winy / (env->tmap->sizey + env->tmap->sizex
		+ 1)) - env->prof * env->tmap->values[y][x + 1]) * env->zoom + env->dy;
	color = ft_max(set_color(env, x, y), set_color(env, x + 1, y));
	draw_line(env, &a, &b, color);
}

static void		vertical(t_env *env, t_point a, int x, int y)
{
	t_point c;
	int		color;

	c.x = (((env->tmap->sizey - y) + x - 1) * (env->winx / (env->tmap->sizey
		+ env->tmap->sizex))) * env->zoom + env->dx;
	c.y = ((x + y + 2) * (env->winy / (env->tmap->sizey + env->tmap->sizex
		+ 1)) - env->prof * env->tmap->values[y + 1][x]) * env->zoom + env->dy;
	color = ft_max(set_color(env, x, y), set_color(env, x, y + 1));
	draw_line(env, &a, &c, color);
}

static void		le_joli_dessin(t_env *env, int x, int y)
{
	t_point a;

	a.x = (((env->tmap->sizey - y) + x) * (env->winx / (env->tmap->sizey
			+ env->tmap->sizex))) * env->zoom + env->dx;
	a.y = ((x + y + 1) * (env->winy / (env->tmap->sizey + env->tmap->sizex
			+ 1)) - env->prof * env->tmap->values[y][x]) * env->zoom + env->dy;
	if (x != env->tmap->sizex - 1)
		horizontal(env, a, x, y);
	if (y != env->tmap->sizey - 1)
		vertical(env, a, x, y);
}

void			draw_isom(t_env *env)
{
	int		x;
	int		y;

	mlx_clear_window(env->mlx, env->win);
	if ((env->img = mlx_new_image(env->mlx, env->winx, env->winy)) == NULL)
		return ;
	if (!(env->pix = mlx_get_data_addr(env->img,
				&(env->bpp), &(env->s_l), &(env->endian))))
		return ;
	y = -1;
	while (++y < env->tmap->sizey)
	{
		x = -1;
		while (++x < env->tmap->sizex)
			le_joli_dessin(env, x, y);
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img, 25, 25);
	mlx_destroy_image(env->mlx, env->img);
	mlx_string_put(env->mlx, env->win, 0, 0, 0x00FFFFFF,
		" wasd/fleches:deplace  *//:profondeur");
	mlx_string_put(env->mlx, env->win, 0, env->winy + 25, 0x00FFFFFF,
			" +/-:zoom  q/esc:quit  i/p:vue  0:reset");
}
