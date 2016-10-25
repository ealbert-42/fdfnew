/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 11:12:23 by ealbert           #+#    #+#             */
/*   Updated: 2016/10/25 18:05:33 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Plus tard
*/

#include "fdf.h"

t_matrix	**matrix_init(t_env *var)
{
	t_matrix	**mtx;
	int			i;
	int			j;

	i = -1;
	mtx = (t_matrix **)malloc(sizeof(t_matrix *));
	while (++i < var->lines)
	{
		j = -1;
		mtx[i] = (t_matrix *)malloc(sizeof(t_matrix) * var->nb);
		while (++j < var->nb)
		{
			mtx[i][j].x = var->p[i][j].x * 30;
			mtx[i][j].y = var->p[i][j].y; * 20;
		}
	}
	return (mtx);
}

void		delete_matrix(t_matrix ***mtx)
{
	int		i;

	i = 0;
	while (*mtx[i])
	{
		free(*mtx[i]);
		*mtx[i] = NULL;
		i++;
	}
	free(*mtx);
	mtx = NULL;
}
