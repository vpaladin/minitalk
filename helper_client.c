#include "minitalk.h"

void	init_bits(char *str)
{
	str[0] = '0';
	str[1] = '0';
	str[2] = '0';
	str[3] = '0';
	str[4] = '0';
	str[5] = '0';
	str[6] = '0';
	str[7] = '0';
}

char	*convert_to_bin(int nb)
{
	char	*bits;
	int		i;

	i = 0;
	bits = malloc(sizeof(char) * SIZE);
	if (!bits)
		error(ERROR_MALLOC);
	init_bits(bits);
	if (nb == 0)
		return (bits);
	while (i < SIZE)
	{
		bits[SIZE - i - 1] = nb % 2 + '0';
		nb /= 2;
		i++;
	}
	i = 0;
	return (bits);
}

void	send_out_char(pid_t pid, int c)
{
	int		i;
	char	*char_byte;

	i = 0;
	char_byte = convert_to_bin(c);
	while (i < 8)
	{
		if (char_byte[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(60);
		i++;
	}
	free(char_byte);
}

void	send_out(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		send_out_char(pid, str[i]);
		i++;
	}
	send_out_char(pid, 0);
}
