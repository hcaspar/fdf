/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcaspar <hcaspar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 11:29:49 by hcaspar           #+#    #+#             */
/*   Updated: 2017/05/23 17:32:12 by hcaspar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>

# define RES_X 1280
# define RES_Y 1024

typedef struct			s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
}						t_mlx;

typedef struct			s_env
{
	t_mlx				mlx;
}						t_env;

void				mlx(t_env *e);

void				hooks(t_env *e);

void 				prog_exit(t_env *e, char *msg);

int					render(t_env *e);

#endif
