/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyvalue_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 16:21:24 by ypark             #+#    #+#             */
/*   Updated: 2020/12/06 17:41:55 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int			key_copy(int l_index, char *str)
{
	int i;

	i = 0;
	while (str[i] != ':')
	{
		if (!is_space(str[i]))
		{
			g_list[l_index].key[i] = str[i];
			i++;
		}
		else
			i++;
	}
	g_list[l_index].key[i] = 0;
	return (1);
}

int			check_possible(int l_index)
{
	int		i;
	char	ch;

	i = 0;
	while (g_list[l_index].key[i])
	{
		ch = g_list[l_index].key[i];
		if (!('0' <= ch && ch <= '9'))
			return (0);
		i++;
	}
	i = 0;
	while (g_list[l_index].value[i])
	{
		ch = g_list[l_index].value[i];
		if (!(' ' <= ch && ch <= '~'))
			return (0);
		i++;
	}
	return (1);
}

int			join_value(char *str, int l_index, int *t_index)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] != ':')
			g_list[l_index].value[(*t_index)++] = str[i++];
		else
		{
			flag = 1;
			i++;
		}
	}
	return (flag);
}

int			push_keyvalue(char **ptr, int size, int l_index)
{
	int			ptr_index;
	int			i;
	int			flag;
	int			t_index;

	key_copy(l_index, ptr[0]);
	i = 1;
	t_index = 0;
	while (i < size)
	{
		ptr_index = 0;
		flag = 0;
		flag = join_value(ptr[i], l_index, &t_index);
		if (i + 1 != size && !flag)
			g_list[l_index].value[t_index++] = ' ';
		i++;
	}
	g_list[l_index].value[t_index] = 0;
	return (check_possible(l_index));
}
