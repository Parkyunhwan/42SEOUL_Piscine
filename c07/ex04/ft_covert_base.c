#include <stdio.h>
#include <stdlib.h>

int		is_space(char ch);
int		is_base_possible(char *base);
int		get_base_index(char ch, char *base);
int		ft_strlen(char *str);
int		get_length(int val, int len);

long long	convert_from_10(char *nbr, char *base)
{
	int		i;
	int		index;
	int		len;
	long long	ret;

	i = 0;
	ret = 0;
	len = ft_strlen(base);
	while ((index = get_base_index(nbr[i], base)) != -1)
	{
		ret *= len;
		ret += index;
		i++;
	}
	return (ret);
}

char		*convert_10_to(long long value, char *base_to, int sign)
{
	int	len;
	char	*ptr;
	int	str_len;
	int	i;
	int	save;
	
	save = value;
	len = ft_strlen(base_to);
	str_len = get_length(value, len);
	if (sign == -1 && value != 0)
		str_len  += 1;
	ptr = (char *)malloc(sizeof(char) * (str_len + 1));
	i = 0;
	while (i < str_len)
	{
		ptr[str_len -1 - i] = base_to[value % len];
		value /= len;
		i++;
	}
	if (sign == -1 && save != 0)
		ptr[0] = '-';
	ptr[str_len] = 0;
	return (ptr);
}

char		*ft_convert_base(char *nbr, char *base_from, char* base_to)
{
	int 		i;
	int 		sign;
	long long	value;
	char		*ret;

	ret = 0;
	if(!is_base_possible(base_from) || !is_base_possible(base_to))
		return (0);
	i = 0;
	sign = 1;
	while (is_space(nbr[i]))
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			sign *= -1;
		i++;
	}
	nbr += i;
	value = convert_from_10(nbr, base_from);
	printf("value : %lld\n", value);
	ret = convert_10_to(value, base_to, sign);
	return (ret);
}

int		main()
{
	printf("%s\n", ft_convert_base(" ++2147483647", "0123456789", "0123456789ABCDEF"));
}
