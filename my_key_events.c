/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:54:51 by gperilla          #+#    #+#             */
/*   Updated: 2017/12/21 17:53:21 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

static void	zoom(int key, t_env *env)
{
	if (key == 78)
	{
		env->zoom -= 0.1;
		env->dx += (env->winx / 2) / 10;
		env->dy += (env->winy / 2) / 10;
	}
	else if (key == 69)
	{
		env->zoom += 0.1;
		env->dx -= (env->winx / 2) / 10;
		env->dy -= (env->winy / 2) / 10;
	}
}

static void	deplace(int key, t_env *env)
{
	if (key == 126 || key == 13)
		env->dy -= 10;
	else if (key == 125 || key == 1)
		env->dy += 10;
	else if (key == 124 || key == 2)
		env->dx += 10;
	else if (key == 123 || key == 0)
		env->dx -= 10;
}

static void	reset(t_env *env)
{
	env->dx = 0;
	env->dy = 0;
	env->zoom = 1;
	env->prof = 2;
}

int			my_key_events(int key, t_env *env)
{
	if (key == 53 || key == 12)
		exit(0);
	else if (key == 78 || key == 69)
		zoom(key, env);
	else if (key == 75)
		env->prof -= 0.5;
	else if (key == 67)
		env->prof += 0.5;
	else if (key == 35)
		env->view = PARA;
	else if (key == 34)
		env->view = ISOM;
	else if ((key >= 123 && key <= 126) || (key >= 0 && key <= 2) || key == 13)
		deplace(key, env);
	else if (key == 82)
		reset(env);
	if (env->view == ISOM)
		draw_isom(env);
	else
		draw_para(env);
	return (1);
}
