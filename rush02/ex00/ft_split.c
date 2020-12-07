/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:49:35 by ypark             #+#    #+#             */
/*   Updated: 2020/12/06 17:45:51 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int			is_space(char ch)
{
	if (ch == ' ' || ch == '\t')
		return (1);
	else
		return (0);
}

int			count_word(char *str)
{
	int i;
	int count;
	int flag;

	i = 0;
	count = 0;
	flag = 0;
	while (str[i])
	{
		if (!flag && !is_space(str[i]))
		{
			flag = 1;
			count++;
		}
		else if (is_space(str[i]))
			flag = 0;
		i++;
	}
	return (count);
}

char		*ft_copyword(char *str, int *start)
{
	char	*p;
	int		i;
	int		flag;
	int		len;
	int		p_index;

	i = *start;
	flag = 0;
	p_index = 0;
	while (is_space(str[i]))
		i++;
	len = i;
	while (str[len] && !is_space(str[len]))
		len++;
	len = len - i;
	p = (char *)malloc(sizeof(char) * (len + 1));
	while (p_index < len)
		p[p_index++] = str[i++];
	p[p_index] = 0;
	*start = i;
	return (p);
}

int			ft_split(char *str, int l_index)
{
	char	**ptr;
	int		w_count;
	int		index;
	int		offset;

	index = 0;
	offset = 0;
	w_count = count_word(str);
	ptr = (char **)malloc(sizeof(char *) * (w_count + 1));
	if (ptr == NULL)
		return (0);
	while (index < w_count)
		ptr[index++] = ft_copyword(str, &offset);
	if (!push_keyvalue(ptr, w_count, l_index))
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	ptr[w_count] = 0;
	index = 0;
	while (index < w_count + 1)
		free(ptr[index++]);
	free(ptr);
	return (1);
}
