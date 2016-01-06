#include <stdio.h>
#include <wchar.h>

int	main(void)
{
	int		a = 48;
	int		*b = &a;

	printf("%#x", (int)b);
	return (0);
}
