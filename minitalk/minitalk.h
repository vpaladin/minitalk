#ifndef MINITALK_H
# define MINITALK_H

# define RL 0
# define LR 1
# define ERROR_MALLOC "ERROR: Unable to allocate memory!\n"
# define ERROR_PID "ERROR: Invalid PID!\n"
# define ERROR_INPUT "ERROR: Invalid input!\n"
# define SIZE 8

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_str
{
	int		i;
	int		byte[8];
	char	*str;
}	t_str;

t_str	g_str;
void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
char	*ft_str_addchar(char *line, char buffer);
void	ft_putnbr(int nb);
void	ft_bzero(void *b, size_t len);
void	send_out(pid_t pid, char *str);
int		error(char *str);
int		ft_square(int pow);

#endif