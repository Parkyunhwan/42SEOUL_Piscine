#include <unistd.h>
void ft_print_numbers(void)
{
	char start='0';
	while(start != '9'){
		write(1, &start, 1);
		start = start + 1;
	}
	write(1, &start, 1);
}
