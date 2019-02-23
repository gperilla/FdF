/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:34:22 by gperilla          #+#    #+#             */
/*   Updated: 2017/12/14 11:53:07 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ISOM 0
# define PARA 1

typedef struct	s_map
{
	int		**values;
	float	sizex;
	float	sizey;
}				t_map;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*pix;
	int		bpp;
	int		s_l;
	int		endian;
	float	winx;
	float	winy;
	float	zoom;
	float	prof;
	int		dx;
	int		dy;
	int		view;
	t_map	*tmap;
}				t_env;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct	s_line
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		xdir;
	int		ydir;
	int		p;
}				t_line;

char			*get_map(char *file_name);

t_map			*to_the_matrix(t_map *tmap, char *map);

void			my_putpixel(t_env *env, int x, int y, int color);

void			draw_line(t_env *env, t_point *pt1, t_point *pt2, int color);

void			draw_isom(t_env *env);

void			draw_para(t_env *env);

int				ft_min(int a, int b);

int				ft_max(int a, int b);

int				ft_abs(int x);

int				set_color(t_env *env, int x, int y);

int				my_key_events(int key, t_env *env);

#endif
