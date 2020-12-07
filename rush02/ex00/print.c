/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 16:26:59 by hakkim            #+#    #+#             */
/*   Updated: 2020/12/06 19:57:33 by hakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	print2(char *str, char *ch, int sp, int *space)
{
	char	tmp[2];

	if (str[sp + 1] != '0')
		find_str(ch, space);
	if (str[sp + 2] != '0')
	{
		tmp[0] = str[sp + 2];
		tmp[1] = '\0';
		find_str(tmp, space);
	}
}

void	print3(char *str, int sp, int *space)
{
	char	ch[3];
	char	tmp[2];

	if (str[sp] != '0')
	{
		tmp[0] = str[sp];
		tmp[1] = '\0';
		find_str(tmp, space);
		find_str("100", space);
	}
	ch[0] = str[sp + 1];
	ch[2] = 0;
	if (str[sp + 1] == '1')
	{
		ch[1] = str[sp + 2];
		find_str(ch, space);
	}
	else
	{
		ch[1] = '0';
		print2(str, ch, sp, space);
	}
}

void	init_str(char *c, char *str)
{
	int		j;
	int		len;

	len = ft_strlen(str);
	if (len % 3 == 1)
	{
		c[0] = '0';
		c[1] = '0';
		j = 2;
		ft_strcpy(j, str, c);
	}
	else if (len % 3 == 2)
	{
		c[0] = '0';
		j = 1;
		ft_strcpy(j, str, c);
	}
	else
	{
		j = 0;
		ft_strcpy(j, str, c);
	}
}

void	printall(char *str, int sp, int *space)
{
	char	*unit;
	int		len;
	int		i;

	len = ft_strlen(str);
	print3(str, sp, space);
	if (sp + 3 < len)
	{
		if (!(str[sp] == '0' && str[sp + 1] == '0' && str[sp + 2] == '0'))
		{
			unit = (char *)malloc(len - sp);
			unit[0] = '1';
			i = 1;
			while (i < len - sp - 2)
				unit[i++] = '0';
			unit[i] = 0;
			find_str(unit, space);
			free(unit);
		}
		printall(str, sp + 3, space);
	}
}

void	print_main(char *str)
{
	char	*tmp;
	int		len;
	int		i;
	int		space;

	len = ft_strlen(str);
	if (len % 3 != 0)
		i = 3 - len % 3;
	else
		i = 0;
	tmp = (char *)malloc(sizeof(char) * (len + i + 1));
	init_str(tmp, str);
	space = 1;
	if (is_zero(tmp))
		find_str("0", &space);
	else
		printall(tmp, 0, &space);
	free(tmp);
}
