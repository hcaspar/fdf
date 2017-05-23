/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 15:28:26 by hcaspar           #+#    #+#             */
/*   Updated: 2017/05/23 17:32:28 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				red_cross(t_env *e)
{
	prog_exit(e, NULL);
	return (0);
}

int				keypress(int key, t_env *e)
{
	key == 53 ? prog_exit(e, NULL) : 0;
	return (0);
}

void			hooks(t_env *e)
{
	mlx_hook(e->mlx.win, 17, (1L << 17), red_cross, e);
	mlx_hook(e->mlx.win, 2, (1L << 0), keypress, e);
}
