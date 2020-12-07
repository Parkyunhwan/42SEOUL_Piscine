#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max);

int main()
{
	int *p;
	int min = 3;
	int max = 1;
	int len = ft_ultimate_range(&p, min, max);
	printf("len : %d\n", len);
	for(int i = 0; i < len; i++)
		printf("%d\n", p[i]);
}

