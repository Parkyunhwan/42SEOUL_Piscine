/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 15:30:04 by hakkim            #+#    #+#             */
/*   Updated: 2020/12/06 15:37:14 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_strcpy(int startindex, char *src, char *dest)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[startindex] = src[i];
		startindex++;
		i++;
	}
	dest[startindex] = 0;
}

int		is_zero(char *str)
{
	while (*str != 0)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}
