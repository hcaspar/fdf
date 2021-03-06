/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 11:28:46 by hcaspar           #+#    #+#             */
/*   Updated: 2017/07/12 15:31:20 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					main(int ac, char **av)
{
	t_env			e;

	if (ac < 2)
		prog_exit(&e, "Bad input");
	parsing(&e, av);
	mlx(&e);
	hooks(&e);
	mlx_loop_hook(e.mlx.mlx, render, &e);
	mlx_loop(e.mlx.mlx);
	return (0);
}
