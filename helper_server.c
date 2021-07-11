#include "minitalk.h"

int	ft_square(int pow)
{
	int	counter;
	int	res;

	if (pow == 0)
		return (1);
	res = 2;
	counter = 1;
	while (counter < pow)
	{
		res = res * 2;
		counter++;
	}
	return (res);
}

char	*ft_str_addchar(char *line, char buffer)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(line);
	res = malloc(sizeof(char) * (len + 2));
	if (!res)
		error(ERROR_MALLOC);
	while (len > 0)
		res[i] = line[i], i++, len--;
	res[i] = buffer;
	i++;
	res[i] = '\0';
	free(line);
	return (res);
}
