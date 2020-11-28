/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 22:23:29 by ypark             #+#    #+#             */
/*   Updated: 2020/11/28 22:27:56 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int k;

	i = 0;
	while (str[i])
	{
		j = 0;
		k = i;
		while (to_find[j])
		{
			if (str[k] != to_find[j])
				break ;
			k++;
			j++;
		}
		if (!to_find[j])
			return (str + i);
		i++;
	}
	return (NULL);
}
