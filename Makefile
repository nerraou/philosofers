NAME = philo
CFLAGS = -Wall -Wextra -Werror
HEADERS = ./includes/philo.h

SRC =  	src/init_params.c\
		src/set_params.c\
		src/ft_atoi.c\
		src/set_forks.c\
		src/set_philo.c\
		src/get_current_time.c\
		src/global_state.c\
		src/philo.c


OBJ =  $(SRC:.c=.o)

INCLUDES_PATH = -I./includes/

all: $(NAME)

%.o: %.c $(HEADERS)
	gcc $(CFLAGS) $(INCLUDES_PATH) -o $@ -c $<

$(NAME): $(OBJ)
	gcc -o $(NAME) $^ $(INCLUDES_PATH)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_B)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT_BONUS)

re: fclean all