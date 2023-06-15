#include <stdio.h>

int main(void)
{
	int a = 10;
	
	printf("%*i\n", 5, a); // * is width indicator for printing. Has to be passed after format string.
	printf("%07i\n", a); // 0 flag indicates zero-padding to the left, until width is fully filled
	printf("%+0*i\n", 7, a); // + explicits the signal. takes a space from width (in this case, substituting a zero)
	printf("%-*i\n", 7, a); // - turns alignment to the right. ignores 0 flag if there's one
	printf("%7.5d\n", a); // .number is the precision indicator. Takes space of width
	printf("%i\n", a); // #x converts a (an int) to lowercase hexadecimal
	printf("%#X\n",	a); // #x converts a (an int) to uppercase hexadecimal
	printf("%d %i\n", 012, 012);
}

