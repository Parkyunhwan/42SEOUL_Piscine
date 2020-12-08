#include <stdlib.h>
#include <stdio.h>

int		is_charset(char *str, int index, char *charset)
{
	int j;

	j = 0;
	while (charset[j])
	{
		if (str[index++] != charset[j++])
			return (0);
	}
	if (!charset[j])
		return (1);
	return (0);
}

int		count_word(char *str, char *charset, int len)
{
	int i;
	int count;
	int flag;
 
	count = 0;
	i = 0;
	flag = 0;
	while (str[i])
	{ 
		if (!flag && !is_charset(str, i, charset))
		{
			flag = 1;
			count++;
		}
		else if (is_charset(str, i ,charset))
		{
			flag = 0;
			i += len;
			continue ;
		}
		i++;
	}
	return (count);
}

char		*ft_copyword(char *str, int *offset, char *charset)
{
	char	*p;
	int	len;
	int	s_word;
	int	i;

	len = 0;
	while (charset[len])
		len++;
	while (is_charset(str, *offset, charset))
		*offset += len;
	s_word = *offset;
	while (str[*offset] && !is_charset(str, *offset, charset))
		(*offset)++;
	len = *offset - s_word;
	p = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
		p[i++] = str[s_word++];
	p[i] = 0;
	return (p);
}

char		**ft_split(char *str, char *charset)
{
	int	w_count;
	char	**ptr;
	int	i;
	int	offset;
	int	len;

	while (charset[len])
		len++;
	w_count = count_word(str, charset, len);
	if (!(ptr = (char **)malloc(sizeof(char *) * (w_count + 1))))
		return (0);
	i = 0;
	offset = 0;
	while (i < w_count)
		ptr[i++] = ft_copyword(str, &offset, charset);
	ptr[w_count] = 0;
	return (ptr);
}

int		main()
{
	char **ptr;
	ptr = ft_split("k aaka aoejo wejofi j qowje ", "  ");
	for (int i = 0; i < 2; i++)
		printf("%s\n", ptr[i]);
}
