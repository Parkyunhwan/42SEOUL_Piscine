/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:00:44 by hakkim            #+#    #+#             */
/*   Updated: 2020/12/06 19:54:35 by hakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	find_str(char *str, int *space)
{
	int i;

	i = 0;
	while (i < g_size)
	{
		if (str_cmp(g_list[i].key, str))
		{
			if (*space == 1)
				*space = 0;
			else
				write(1, " ", 1);
			ft_putstr(g_list[i].value);
			return ;
		}
		i++;
	}
}

int		str_cmp(char *key, char *find)
{
	int i;

	i = 0;
	while (find[i] != 0 || key[i] != 0)
	{
		if (find[i] != key[i])
			return (0);
		i++;
	}
	if (find[i] == 0 && key[i] == 0)
		return (1);
	else
		return (0);
}
