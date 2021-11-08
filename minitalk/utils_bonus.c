#include "minitalk_bonus.h"

int	error(char *str)
{
	ft_putstr(str);
	exit(1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != 0)
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	long	n;
	int		num;
	char	c;

	n = nb;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	num = n % 10;
	if (n >= 10)
		ft_putnbr(n / 10);
	c = num + '0';
	write(1, &c, 1);
}

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
