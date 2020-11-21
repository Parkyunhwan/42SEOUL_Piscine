/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 01:56:41 by ypark             #+#    #+#             */
/*   Updated: 2020/11/22 01:58:12 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_reverse_alphabet(void)
{
	char ch;

	ch = 'z';
	while (ch != 'a')
	{
		write(1, &ch, 1);
		ch--;
	}
	write(1, &ch, 1);
}
