#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(char first, ...)
{
	char	current;
	va_list	args;

	va_start(args, first);
	current = 'x';

	while (current != '\0')
	{
		current = va_arg(args, char);
		write(1, &current, 1);
		write(1, "\n", 1);
	}
	va_end(args);
	return (0);
}

int main(void)
{
	ft_printf('0', 'a', 'b', 'c', '\0');
}
