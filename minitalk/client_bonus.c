#include "minitalk_bonus.h"

pid_t	check_pid(char *str)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (str[i] != 0)
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			error(ERROR_PID);
		i++;
	}
	i = 0;
	pid = 0;
	while (str[i] != 0)
	{
		pid = pid * 10 + (str[i] - 48);
		if (pid > 99998)
			error(ERROR_PID);
		i++;
	}
	if (pid <= 0)
		error(ERROR_PID);
	return (pid);
}

void	send_out_char(pid_t pid_server, unsigned char c)
{
	int	mask;
	int	bit;

	mask = 1 << 7;
	bit = 8;
	while (bit > 0)
	{
		if (mask & c)
			kill(pid_server, SIGUSR1);
		else
			kill(pid_server, SIGUSR2);
		mask >>= 1;
		usleep(60);
		bit--;
	}
}

static void	send_out(char *str, pid_t pid_server)
{
	int		i;
	pid_t	pid_cl;
	char	*pid_client;

	i = 0;
	while (str[i] != 0)
	{
		send_out_char(pid_server, str[i]);
		i++;
	}
	send_out_char(pid_server, 0);
	pid_cl = getpid();
	pid_client = ft_itoa(pid_cl);
	while (*pid_client != 0)
	{
		send_out_char(pid_server, *pid_client);
		pid_client++;
	}
	send_out_char(pid_server, 0);
	usleep(100);
}

static void	handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "The message is received by server\n", 34);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid_server;

	if (argc != 3)
		error(ERROR_INPUT);
	pid_server = check_pid(argv[1]);
	send_out(argv[2], pid_server);
	signal(SIGUSR1, handler);
	pause();
	return (0);
}
