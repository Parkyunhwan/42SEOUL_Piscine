#include <stdio.h>

int	*ft_range(int min, int max);
int main()
{
	int *p;
	int min = -14;
	int max = 9;
	p = ft_range(min, max);	
	for(int i = 0; i < max - min; i++)
		printf("%d\n", p[i]);
}
