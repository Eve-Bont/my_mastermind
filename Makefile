NAME = libmymastermind.a
SRC = fonction.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
TEST = my_mastermind.exe

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all

.PHONY: all clean fclean re