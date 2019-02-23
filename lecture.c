/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:40:35 by gperilla          #+#    #+#             */
/*   Updated: 2017/12/21 18:01:47 by gperilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

char	*remove_dblspace(char *map)
{
	char	*ret;
	int		i;
	int		j;

	ret = malloc(sizeof(char) * ft_strlen(map) + 1);
	i = -1;
	j = 0;
	while (map[++i] != '\0')
	{
		if (!(map[i] == ' ' && map[i + 1] == ' '))
			ret[j++] = map[i];
	}
	ret[j] = '\0';
	free(map);
	return (ret);
}

char	*get_map(char *file_name)
{
	int		fd;
	char	*line;
	char	*map;
	char	*ret;

	fd = open(file_name, O_RDONLY);
	if (!(map = malloc(sizeof(char))))
		return (NULL);
	map[0] = '\0';
	while (get_next_line(fd, &line) > 0)
	{
		map = ft_strjoin_free(map, line, 1);
		map = ft_strjoin_free(map, " \n", 1);
		free(line);
	}
	if (!(ret = remove_dblspace(map)))
		return (NULL);
	return (ret);
}
