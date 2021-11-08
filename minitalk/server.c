#include "minitalk.h"

void	print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putstr("\n");
}

void	add_char(void)
{
	int		pow;
	int		character;

	pow = 0;
	character = 0;
	while (pow < 8)
	{
		if (g_str.byte[SIZE - pow - 1] == 1)
			character += ft_square(pow);
		pow++;
	}
	write(1, &character, 1);
	g_str.i = 0;
}

void	handler(int command)
{
	if (command == SIGUSR1)
		command = 0;
	else
		command = 1;
	g_str.byte[g_str.i] = command;
	g_str.i++;
	if (g_str.i >= 8)
		add_char();
}

int	main(void)
{
	print_pid();
	ft_putstr("Waiting for a message...\n");
	g_str.str = malloc(sizeof(char));
	if (!g_str.str)
		error(ERROR_MALLOC);
	g_str.str[0] = '\0';
	g_str.i = 0;
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
}
