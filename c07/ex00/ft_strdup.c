/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 18:54:52 by ypark             #+#    #+#             */
/*   Updated: 2020/12/07 19:39:56 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char		*ft_strdup(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i])
		i++;
	if(!(ptr = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

int			main()
{
	char *p;
	p = ft_strdup("abcdefg   123");
	printf("%s\n", p);
	return (0);
}
