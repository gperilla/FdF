/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 14:20:36 by gperilla          #+#    #+#             */
/*   Updated: 2018/01/05 10:06:32 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>

#include "fdf.h"
#include "libft.h"

void		init(t_env *env, char **argv)
{
	char	*map;

	env->dx = 0;
	env->dy = 0;
	if (!(map = get_map(argv[1])))
		exit(-1);
	if (!(env->tmap = malloc(sizeof(t_map))))
		exit(-1);
	env->view = ISOM;
	env->zoom = 1;
	env->prof = 2;
	if (!(env->tmap = to_the_matrix(env->tmap, map)))
		exit(-1);
	env->winx = ft_min(1920, (env->tmap->sizex + 1) * 20);
	env->winy = ft_min(1080, (env->tmap->sizey + 1) * 20);
}

int			main(int argc, char **argv)
{
	t_env truc;

	if (argc != 2)
		return (0);
	init(&truc, argv);
	if ((truc.mlx = mlx_init()) == NULL)
		return (-1);
	if ((truc.win = mlx_new_window(truc.mlx, truc.winx + 50,
					truc.winy + 50, "FdF")) == NULL)
		return (-1);
	if ((truc.img = mlx_new_image(truc.mlx, truc.winx, truc.winy)) == NULL)
		return (-1);
	if (!(truc.pix = mlx_get_data_addr(truc.img,
					&(truc.bpp), &(truc.s_l), &(truc.endian))))
		return (-1);
	draw_isom(&truc);
	mlx_key_hook(truc.win, my_key_events, &truc);
	mlx_loop(truc.mlx);
	return (0);
}
