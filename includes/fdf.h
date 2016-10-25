/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 15:01:59 by ealbert           #+#    #+#             */
/*   Updated: 2016/10/25 18:51:56 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/*
** Defines for FdF
*/

# define WIN_H 999
# define WIN_W 666
# define ROTATE 0.5
# define TSLT_H WIN_H / 20
# define TSLT_W WIN_W / 20


/*
** Includes
*/

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>

/*
** Helpful structures
*/

typedef struct		t_matrix
{
	int				x;
	int				y;
}					t_matrix;

typedef struct			s_coor
{
	float			x;
	float			y;
	float			z;
	float			off;
}					t_coor;

typedef struct		s_env
{
	void			*mlx;
	void			*img;
	void			*win;
	char			*data;
	int				bpp;
	int				endian;
	int				s_line;
	float			rotx;
	float			roty;
	float			rotz;
	t_coor			**p;
	unsigned int	**color;
	int				fd;
	char			*line;
	int				nb;
	int				lines;
}					t_env;

/*
** Functions
*/

void			error_handle(char *s);
t_env			*save_map(t_env *var);
t_env			*parser(t_env *var);
void			commands_disp(t_env *v);
void			mlx_calls(t_env *v);

#endif
