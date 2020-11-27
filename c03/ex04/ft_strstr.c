#include <stdio.h>
char		*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	int k;

	i = 0;
	while(str[i])
	{
		j = 0;
		k = i;	
		while(to_find[j])
		{
			if (str[k] != to_find[j])
				break;
			k++;
			j++;
		}
		if (!to_find[j])
			return (str+i); 
		i++;
	}
	return NULL;
}

int main()
{
	char a[20] = "ajoejf";
	char b[20] = "joejfaoje";
	
	printf("%s\n", ft_strstr(a, b));
}
