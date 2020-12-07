/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:27:33 by ypark             #+#    #+#             */
/*   Updated: 2020/12/07 20:48:28 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while(str[i])
		i++;	
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *ptr;
	int i;
	int len;

	len = 0;
	while (i < size)
		len += ft_strlen(strs[i]);	
	len += (ft_strlen(sep) * size);
	if(!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (!size)
		return (ptr);
	i = 0;
	return (ptr);
}

int main()
{
	char *ptr;
	char a[3][20] = {"afeofjoe","aewfqwf ", "hoijodjfgo"};
	char s[] = " 1 ";
	ptr = ft_strjoin(3, a, s); 
}
