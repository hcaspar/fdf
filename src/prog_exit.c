/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:15:37 by hcaspar           #+#    #+#             */
/*   Updated: 2017/07/12 15:32:31 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 				prog_exit(t_env *e, char *msg)
{
	t_map			*tmp_map;

	if (e->mlx.img)
		mlx_destroy_image(e->mlx.mlx, e->mlx.img);
	if (e->mlx.win)
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	if (msg)
		ft_putendl(msg);
	while (e->map)
	{
		tmp_map = e->map->next;
		free(e->map);
		e->map = tmp_map;
	}
	exit(0);
}
