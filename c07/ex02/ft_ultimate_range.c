/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:38:22 by ypark             #+#    #+#             */
/*   Updated: 2020/12/07 20:15:04 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int len;
	int i;

	if (min >= max)
		return (0);	
	len = max - min;

	if(!(*range = (int *)malloc(sizeof(int) * len)))
		return (-1);
	i = 0;
	while(i < len)
		(*range)[i++] = min++;
	return (len);
}
