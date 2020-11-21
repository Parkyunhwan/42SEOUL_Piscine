/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:53:42 by ypark             #+#    #+#             */
/*   Updated: 2020/11/22 01:56:05 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_numbers(void)
{
	char start;

	start = '1';
	while (start != '9')
	{
		write(1, &start, 1);
		start = start + 1;
	}
	write(1, &start, 1);
}
