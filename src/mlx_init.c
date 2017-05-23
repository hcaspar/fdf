/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:07:16 by hcaspar           #+#    #+#             */
/*   Updated: 2017/05/23 15:27:23 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				mlx(t_env *e)
{
	e->mlx.mlx = mlx_init();
	if (!e->mlx.mlx)
		prog_exit(e, "mlx init error");
	e->mlx.win = mlx_new_window(e->mlx.mlx, RES_X, RES_Y, "fdf.h");
	if (!e->mlx.win)
		prog_exit(e, "mlx window error");
	e->mlx.img = mlx_new_image(e->mlx.mlx, RES_X, RES_Y);
	if (!e->mlx.img)
		prog_exit(e, "image error");
}
