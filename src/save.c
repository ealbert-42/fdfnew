/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 13:54:23 by ealbert           #+#    #+#             */
/*   Updated: 2016/10/25 18:52:18 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file contains functions related to the saving of the map in the
** arguments of the main.
*/

#include "fdf.h"

char	**fresh_clean(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
	{
		free(tab[i]);
		tab[i] = ft_strnew(0);
	}
	return (tab);
}

t_env			*get_tab(t_env *var, char **tab, int i)
{
	int		j;

	j = 0;
	if (!(var->p[i] = (t_coor *)malloc(sizeof(t_coor) * var->nb)))
		error_handle("Get Tab : malloc of lines failed.");
	while (j < var->nb)
	{
		var->p[i][j].x = (float)j;
		var->p[i][j].y = (float)i;
		var->p[i][j].z = (float)ft_atoi(tab[j]);
		var->p[i][j].off = 0.;
		j++;
	}
	return (var);
}

t_env			*save_map(t_env *var)
{
	int		ret;
	int		i;
	char	**tab;
	char	*line;

	line = ft_strnew(0);
	i = 0;
	if (!(var->p = (t_coor **)malloc(sizeof(t_coor *) * var->lines + 1)))
		error_handle("Could not allocate.");
	while ((ret = get_next_line(var->fd, &line)))
	{
		tab = ft_strsplit(line, ' ');
		var = get_tab(var, tab, i);
		tab = fresh_clean(tab);
		i++;
	}
	ft_strdel(&line);
	close(var->fd);
	return (var);
}
