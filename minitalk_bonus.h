#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

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

void	ft_putstr(char *str);
size_t	ft_strlen(const char *s);
void	ft_putnbr(int nb);
int		error(char *str);
char	*ft_itoa(int n);
int		ft_atoi(char *str);
char	*ft_str_addchar(char *line, char buffer);
void	print_pid(void);

#endif