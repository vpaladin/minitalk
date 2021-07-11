NAME	=	client
NAME_SV =	server

NAME_BONUS		=	client_bonus
NAME_SV_BONUS 	=	server_bonus

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

SRC		=	client.c utils.c helper_client.c

SRC_CV	=	server.c utils.c helper_server.c

SRC_BONUS		=	client_bonus.c utils_bonus.c ft_itoa_bonus.c

SRC_CV_BONUS	=	server_bonus.c utils_bonus.c ft_itoa_bonus.c

HEADER	=	minitalk.h

HEADER_BONUS	=	minitalk_bonus.h

.PHONY	:	all clean fclean re

all		:	$(NAME) $(NAME_SV)

$(NAME)	: $(SRC) $(HEADER)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

$(NAME_SV)	: $(SRC_CV) $(HEADER)
	$(CC) $(CFLAGS) $(SRC_CV) -o $(NAME_SV)

bonus	:	$(NAME_BONUS) $(NAME_SV_BONUS)

$(NAME_BONUS)		: $(SRC_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(SRC_BONUS) -o $(NAME_BONUS)

$(NAME_SV_BONUS)	: $(SRC_CV_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(SRC_CV_BONUS) -o $(NAME_SV_BONUS)

clean	:
	@$(RM) *.o

fclean	:	clean
	@$(RM) $(NAME) $(NAME_SV)
	@$(RM) $(NAME_BONUS) $(NAME_SV_BONUS)

re		:	fclean all
