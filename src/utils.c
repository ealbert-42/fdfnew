/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ealbert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 14:47:07 by ealbert           #+#    #+#             */
/*   Updated: 2016/10/17 14:53:02 by ealbert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** This file contains useful functions that aren't included in the library
** "libft".
**
** strisdigit : checks if a string is filled with digits and spaces only.
** 		It returns 1 when the string is only filled with digits and spaces
** 		It returns 0 when the string contains another character.
*/

#include "fdf.h"

int		strisdigit(char *s)
{
	int		i;

	i = 0;
	while (ft_isdigit(s[i]) || s[i] == ' ' || s[i] == '	')
		i++;
	return ((i == ft_strlen(s)) ? 1 : 0);
}
