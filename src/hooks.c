/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 18:01:24 by ealbert           #+#    #+#             */
/*   Updated: 2016/10/25 17:50:56 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This files contains functions related to the minilibx, especially the
** management of hooks.
**
**
*/

#include "fdf.h"

static int	refresh(t_env *var)
{
	draw(var);
	commands_disp();
}

static int	on_keydown(int keycode, t_env *var)
{
	ft_putstr("Your keycode is ");
	ft_putnbr(keycode);
	ft_putendl(" !");
	ft_putnbr(var->nb);
	ft_putendl("");
	if (keycode = 53)
		exit(1);
	return (0);
}

static int	on_mouseclick(int keycode, int x, int y, t_env *var)
{
	ft_putstr("Your keycode is ");
	ft_putnbr(keycode);
	ft_putendl(" !");
	ft_putnbr(x);
	ft_putstr(" et ");
	ft_putnbr(y);
	ft_putendl("");
	return (var->sizeline);
}

void		mlx_calls(t_env *v)
{
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, WIN_H, WIN_W, "FdF");
	v->img = mlx_new_image(v->mlx, WIN_H, WIN_W);
	v->data = mlx_get_data_addr(v->img, &(v->bpp), &(v->s_line), &(v->end));
	mlx_hook(v->win, 2, 1, &on_keydown, &v);
	mlx_mouse_hook(v->win, on_mouseclick, v);
	mlx_loop(v->mlx);
}
