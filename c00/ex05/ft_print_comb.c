/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 02:01:08 by ypark             #+#    #+#             */
/*   Updated: 2020/11/22 03:49:26 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_comb(void)
{
	char numbers[3];
	int val;

	val = 12;
	while (val < 1000)
	{
		numbers[0] = val / 100 + '0';
		numbers[1] = (val % 100) / 10 + '0';
		numbers[2] = (val % 10) + '0';
		if (numbers[0] < numbers[1] && numbers[1] < numbers[2])
		{
			write(1, &numbers, 3);
			if (!(numbers[0] == '7' && numbers[1] == '8' && numbers[2] == '9'))
			{
				write(1, ", ", 2);
			}
		}
		val++;
	}
}
