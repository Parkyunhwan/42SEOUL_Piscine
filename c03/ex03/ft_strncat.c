#include <stdio.h>
char		*ft_strncat(char *dest, char* src, unsigned int nb)
{
	int	i;
	char	*ptr;
	
	ptr = dest; 
	while(*ptr)
		ptr++;
	i = 0;
	while(*src && nb)
	{
		*ptr = *src;
		ptr++;
		src++;
		nb--;
	}
	*ptr = '\0';
	return (dest);
}

int main()
{
	char d[10] = "abcd";
	char s[10] = "efgh";
	printf("%s", ft_strncat(d, s, 3));
}
