#include "my_libc.h"

static size_t	sizenum_base_u(unsigned long long n, int base)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= base;
	}
	return (count);
}

char	*utoa_base(unsigned long long n, int base, char *chr)
{
	char				*str;
	int					len;

	len = sizenum_base_u(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = chr[(n % base)];
		n /= base;
	}
	return (str);
}