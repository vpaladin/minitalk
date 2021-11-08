#include "minitalk_bonus.h"

void	ft_bzero(void *b, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = 0;
		i++;
	}
}

void	received(int c)
{
	static char	pid_client[5];
	static int	i;
	pid_t		pid_cl;

	pid_client[i] = c;
	i++;
	if (c == 0)
	{
		i = 0;
		pid_cl = ft_atoi(pid_client);
		usleep(200);
		kill(pid_cl, SIGUSR1);
		ft_bzero(pid_client, 5);
	}
}

void	print(int c)
{
	static int	k = 0;
	static char	buff[1000];

	buff[k] = c;
	k++;
	if (k == 999 || c == 0)
	{
		write(1, buff, ft_strlen(buff));
		k = 0;
		ft_bzero(buff, ft_strlen(buff));
	}
}

static void	handler(int sig)
{
	static int	i = 0;
	static int	c = 0;
	static int	mask = 128;
	static int	flag = 1;

	if (sig == SIGUSR1)
		c = mask | c;
	mask = mask >> 1;
	i++;
	if (i == 8)
	{
		if (flag == 1)
			print(c);
		else
			received(c);
		if (c == 0)
			flag = flag * -1;
		i = 0;
		c = 0;
		mask = 128;
	}
}

int	main(void)
{
	print_pid();
	ft_putstr("Waiting for a message...\n");
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}
