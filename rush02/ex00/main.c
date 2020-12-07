/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 12:12:01 by hakkim            #+#    #+#             */
/*   Updated: 2020/12/06 20:30:47 by hakkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		chk_nb(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	if (len > 39)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int		main(int n, char **arr)
{
	if (n == 2)
	{
		if (!(read_file("numbers.dict") && chk_nb(arr[1])))
			return (0);
		print_main(arr[1]);
		free(g_list);
	}
	else if (n == 3)
	{
		if (!(read_file(arr[1]) && chk_nb(arr[2])))
			return (0);
		print_main(arr[2]);
		free(g_list);
	}
	else
		write(1, "Error\n", 6);
}
