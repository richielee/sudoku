NAME = sudoku

SRC = helpers.c helpers2.c helpers3.c main.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra
CC = gcc

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ) : $(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all, re, clean, fclean
