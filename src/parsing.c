/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:43:26 by hcaspar           #+#    #+#             */
/*   Updated: 2017/07/12 15:34:44 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				map_add(int fd, t_map **begin_list)
{
	t_map			*new;
	char			*line;

	new = (t_map*)malloc(sizeof(t_map));
	if (!(*begin_list))
		*begin_list = new;
	line = NULL;
	while (get_next_line(fd, &line))
	{

	}
}

void				parsing(t_env *e, char **av)
{
	int				i;
	int				fd;

	e->map = NULL;
	i = 0;
	while (av[++i])
	{
		fd = open(av[i], O_RDONLY);
		if (fd == -1)
			prog_exit(e, "Open error");
		map_add(fd, &(e->map));
		close(fd);
		if (fd == -1)
			prog_exit(e, "Close error");
	}
}
