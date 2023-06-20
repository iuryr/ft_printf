#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	int ret_ft;
	int	ret_og;

	ret_ft = ft_printf("string: %c %c %c\n", 'a', 'b', 'c');
	ret_og = printf("string: %c %c %c\n", 'a', 'b', 'c');
	printf("Retorno ft_printf: %i\n", ret_ft);
	printf("Retorno printf: %i\n", ret_og);

	printf("\n");

	ret_ft = ft_printf("String %c %s\n", 'a', "outra string");
	ret_og = printf("String %c %s\n", 'a', "outra string");
	printf("Retorno ft_printf: %i\n", ret_ft);
	printf("Retorno printf: %i\n", ret_og);

	printf("\n");

	ret_ft = ft_printf("String %c %s %i %d\n", 'a', "outra string", -42, 100);
	ret_og = printf("String %c %s %i %d\n", 'a', "outra string", -42, 100);
	printf("Retorno ft_printf: %i\n", ret_ft);
	printf("Retorno printf: %i\n", ret_og);

	printf("\n");

	ret_ft = ft_printf("String %u\n", 44294967296);
	ret_og = printf("String %u\n", (unsigned int) 44294967296);
	printf("Retorno ft_printf: %i\n", ret_ft);
	printf("Retorno printf: %i\n", ret_og);
}
