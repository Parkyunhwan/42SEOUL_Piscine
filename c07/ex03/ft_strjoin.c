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

char		*ft_strcat(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])	
		s1[i++] = s2[j++];
	s1[i] = 0;
	return (s1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *ptr;
	int i;
	int len;

	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);	
	if (size > 0)
		len += (ft_strlen(sep) * (size -1));
	if(!(ptr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (!size)
		return (ptr);
	i = 0;
	while (i < size)
	{
		ptr = ft_strcat(ptr, strs[i]);
		if (i + 1 != size)
			ptr = ft_strcat(ptr, sep);
		i++;
	}
	ptr[len] = 0;
	printf("len : %d\n", len);
	return (ptr);
}

int main()
{
	char *ptr;
	char *a[3]; 
	a[0] = "aoejf";
	a[1] = "ewe";
	a[2] = "qok";
	char s[] = ",";
	ptr = ft_strjoin(3, a, s); 
	printf("%s\n", ptr);
}
