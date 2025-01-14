SRCS = 	src/main.c \
		src/error_manager.c \
		src/parsing.c \
		src/exec_shell.c \
		src/process_manager.c \


OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilibft/include -Iinclude -g3

NAME = pipex

LIB = .libft/libft.a

all: $(NAME)

lib:
	make -C ./libft

$(NAME): lib $(OBJS)
	$(CC) $(OBJS) ./libft/libft.a -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -rf ./src/*.o
	make clean -C ./libft

fclean: clean 
	rm -f $(NAME)
	make fclean -C ./libft

re:	fclean all

.PHONY: all compil c lib clean fclean re