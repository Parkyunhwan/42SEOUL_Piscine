/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 19:13:13 by ypark             #+#    #+#             */
/*   Updated: 2020/12/07 20:06:56 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	// -2 -1 0 1 2
	int len;
	int *ptr;
	int i;

	i = 0;
	ptr = 0;
	if (min >= max)
		return (ptr);
	else
		len = max - min;
	if(!(ptr = (int*)malloc(sizeof(int) * (len + 1))))//int형도 +1 더줘야 하나??
		return (0);
	while (i < len)
		ptr[i++] = min++;	
	ptr[i] = 0;	
	return (ptr);
}
