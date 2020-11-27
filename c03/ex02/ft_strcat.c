#include <stdio.h>
char		*ft_strcat(char *dest, char* src)
{
	int	i;
	char	*ptr;
	
	ptr = dest; 
	while(*ptr)
		ptr++;
	i = 0;
	while(*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = '\0';
	return (dest);
}

int main()
{
	char d[10] = "abcd";
	char s[10] = "efgh";
	printf("%s", ft_strcat(d, s));
}
