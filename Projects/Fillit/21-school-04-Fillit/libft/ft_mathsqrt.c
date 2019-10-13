#include "libft.h"

double	ft_mathsqrt(int n)
{
	int i;

	i = 1;
	if (n < 0)
		return (-1);
	if (!n)
		return (0);
	while (i * i < n)
		i++;
	if (!(n % i))
		return (i);
	else
		return (n / i);
}
