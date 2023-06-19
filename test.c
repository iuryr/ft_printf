#include "ft_printf.h"

int main(void)
{
	ft_printf("String %c %c %c\n", 'a', 'b', 'c');

	ft_printf("String %c %s", 'a', "outra string");
	ft_printf("\n");

	ft_printf("String %c %s %i", 'a', "outra string", 42);
}
