#include "libft.h"

int	ft_printf(const char *format, ...);
size_t	prtf_putstr(char *str);
size_t	print_int(int nbr);
size_t print_uint(unsigned int nbr);
char	*uitohex(unsigned int n);
size_t	print_hex(unsigned int n, char c);
size_t	print_voidp(void *p);
