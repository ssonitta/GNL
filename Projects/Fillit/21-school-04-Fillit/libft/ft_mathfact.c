#include "libft.h"

size_t	ft_mathfact(int n)
{
	size_t r;

	if (n < 0)
		return (0);
	r = 1;
	while (n > 1)
		r *= (size_t)n--;
	return (r);
}
