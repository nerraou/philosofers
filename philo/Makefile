NAME = philo
CFLAGS = -Wall -Wextra -Werror 
HEADERS = ./includes/philo.h

SRC =  	src/init.c\
		src/ft_calloc.c\
		src/ft_atoi.c\
		src/ft_puterror.c\
		src/print_state.c\
		src/philo.c\
		src/monitor.c\
		src/time_to_ms.c\
		src/join_and_free_philos.c\
		src/create_philos.c\
		src/main.c


OBJ =  $(SRC:.c=.o)

INCLUDES_PATH = -I./includes/

all: $(NAME)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) $(INCLUDES_PATH) -o $@ -c $<

$(NAME): $(OBJ)
	gcc -o $(NAME) $^ $(INCLUDES_PATH) -lpthread

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_BONUS)

re: fclean all