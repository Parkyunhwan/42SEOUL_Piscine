#include <string.h>
#include <stdio.h>
unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	int *ptr;
	int i;
	int j;
	int len;
	int tmp;

	i = 0;
	while(dest[i])
		i++;
	tmp = i;
	j = 0;
	while(src[j] && i + 1 < size)
	{
		dest[i] = src[j];	
		i++;
		j++;
	}
	dest[i] = '\0';
	while(src[j])
		j++;	
	if (size < tmp)
		return (j + size);
	else
		return (j + tmp);
}

int main()
{
	char a[20] = "aeasdfaef";
	char b[20] = "eij";
	unsigned int s = 4;
	printf("%u\n", ft_strlcat(a, b, s));
	printf("%s\n", a);
	char c[20] = "aeasfasff";
	char d[20] = "eij";
	printf("%lu\n", strlcat(c, d, s));
	printf("%s\n", c);
}
