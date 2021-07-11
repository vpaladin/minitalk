#include "minitalk.h"

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

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
		error(ERROR_INPUT);
	pid = check_pid(argv[1]);
	str = argv[2];
	send_out(pid, str);
	ft_putstr("Message sent.\n");
	return (0);
}
