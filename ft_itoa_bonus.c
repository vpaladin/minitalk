#include "minitalk_bonus.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static	char	*ft_strrev(char *str)
{
	int		length;
	int		i;
	char	t;

	i = 0;
	length = 0;
	while (str[length])
		length++;
	length--;
	while (i < length)
	{
		t = str[i];
		str[i] = str[length];
		str[length] = t;
		length--;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;
	long	res;

	i = 0;
	res = n;
	len = ft_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	if (res < 0)
		res = -res;
	if (res == 0)
		str[i++] = '0';
	while (res != 0)
	{
		str[i++] = (res % 10) + '0';
		res /= 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}

int	ft_atoi(char *str)
{
	int		res;
	long	num;

	num = 0;
	if (*str == '+')
		str++;
	while (*str != 0)
	{
		if (*str >= '0' && *str <= '9')
		{
			num = (num * 10) + (*str - '0');
			str++;
		}
		else
			return (0);
	}
	res = (int)num;
	return (num);
}
