/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_the_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:39:48 by gperilla          #+#    #+#             */
/*   Updated: 2018/01/05 10:09:06 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "fdf.h"

int		nb_col(char *map)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (map[i] == ' ')
		++i;
	while (map[i] != '\n' && map[i] != '\0')
	{
		if (map[i] == ' ')
			++size;
		++i;
	}
	return (size);
}

int		nb_line(char *map)
{
	int size;
	int i;

	size = 0;
	i = 0;
	while (map[i] != '\0')
		if (map[i++] == '\n')
			++size;
	return (size);
}

int		gain_a_few_lines(t_map *tmap, char *map)
{
	int		i;
	int		j;
	char	**tab;

	i = -1;
	while (++i < tmap->sizey)
		if (!(tmap->values[i] = malloc(sizeof(int) * tmap->sizex)))
			return (0);
	if (!(tab = ft_strsplit(map, ' ')))
		return (0);
	i = -1;
	while (++i < tmap->sizey)
	{
		j = -1;
		while (++j < tmap->sizex)
			tmap->values[i][j] = ft_atoi(tab[j + (i * (int)tmap->sizex)]);
	}
	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (1);
}

t_map	*to_the_matrix(t_map *tmap, char *map)
{
	if (tmap)
		free(tmap);
	if (!(tmap = malloc(sizeof(t_map))))
		return (NULL);
	tmap->sizey = nb_line(map);
	tmap->sizex = nb_col(map);
	if (!(tmap->values = malloc(sizeof(int*) * tmap->sizey)))
		return (0);
	if (!(gain_a_few_lines(tmap, map)))
		return (NULL);
	free(map);
	return (tmap);
}
