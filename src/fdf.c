/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 12:52:59 by ealbert           #+#    #+#             */
/*   Updated: 2016/10/25 17:46:36 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file contains the main function and the error handling.
**
** commands_disp(): Displays the commands of the program.
**
** error_handle() : Writes an error message on the screen and exit the program.
**
** main() : Initializes the program and calls the important parts of it.
*/

#include "fdf.h"
#include "libft.h"

void	commands_disp(t_env *v)
{
	mlx_string_put(v->mlx, v->win, 0, 0, 0xEFEFEF, "Esc     = Quit");
	mlx_string_put(v->mlx, v->win, 0, 15, 0xEFEFEF, "Arrows  = Move");
	mlx_string_put(v->mlx, v->win, 0, 30, 0xEFEFEF, "2/4/6/8 = Rotate");
	mlx_string_put(v->mlx, v->win, 0, 45, 0xEFEFEF, "C       = Reset");
	mlx_string_put(v->mlx, v->win, 0, 60, 0xEFEFEF, "Num+    = Zoom In");
	mlx_string_put(v->mlx, v->win, 0, 75, 0xEFEFEF, "Num-    = Zoom Out");
}

void	error_handle(char *s)
{
	ft_putendl(s);
	exit(0);
}

t_env	*var_init(t_env *var)
{
	var->bpp = 4;
	var->s_line = WIN_W;
	var->endian = 1;
}

int		main(int ac, char **av)
{
	t_env	*var;

	if (ac != 2)
		error_handle("Usage : ./fdf \"MAP_NAME\"");
	if (!(var = (t_env*)malloc(sizeof(t_env))))
		error_handle("malloc did not managed to allocate memory.");
	if ((var->fd = open(av[1], O_RDONLY)) == -1)
		error_handle("Did not managed to open the file.");
	var = parser(var);
	var->fd = open(av[1], O_RDONLY);
	var = save_map(var);
	mlx_calls(var);
	return (0);
}
