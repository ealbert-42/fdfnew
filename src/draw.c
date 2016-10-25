/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:15:15 by ealbert           #+#    #+#             */
/*   Updated: 2016/10/25 19:00:22 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Plus tard
*/

#include "fdf.h"

void		draw_line(t_env *v, unsigned int *px)
{
	// a remplir avec les donnees de line param
}

void		line_param();
{
	// a remplir avec mtx et pts
}
void		draw(t_env *v)
{
	unsigned int	*px;
	int				i;
	int				j;

	i = -1;
	px = (unsigned int *)v->data;
	while (++i < var->lines)
	{
		j = -1;
		while (++j < var->nb)
			px[v->mtx[i][j].x * v->s_line + v->mtx[i][j].y] = v->color[i][j];
	}
}
