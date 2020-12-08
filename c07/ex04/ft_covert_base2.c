#include <stdlib.h>

int		is_space(char ch)
{

	if (ch == '\t' || ch == ' ' || \
		ch == '\r' || ch == '\v' || \
		ch == '\n' || ch == '\f')
		return (1);
	return (0);
}

int		is_base_possible(char *base)
{
	int i;
	int j;
	int len;

	len = 0;
	while(base[len])
		len++;
	if (len < 2)
		return (0);
	i = 0;
	while(i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if(is_space(base[i]))
			return (0);
		j = i + 1;
		while(j < len)
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	return (1);
}

int		get_base_index(char ch, char *base)
{
	int i;

	i = 0;
	while(base[i])	
	{
		if (base[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}

int		get_length(int val, int len)
{
	int i;

	i = 0;
	if (val == 0)
		return (1);
	while(val)
	{
		val /= len;
		i++;
	}
	return (i);
}
