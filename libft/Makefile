SRCS = 	convert/ft_atoi.c \
		strings/ft_bzero.c \
		mem/ft_calloc.c \
		strings/ft_isalnum.c \
		strings/ft_isalpha.c \
		strings/ft_isascii.c \
		strings/ft_isdigit.c \
		strings/ft_isprint.c \
		strings/ft_sort_int_tab.c \
		mem/ft_memchr.c \
		mem/ft_memcmp.c \
		mem/ft_memcpy.c \
		mem/ft_memmove.c \
		mem/ft_memset.c \
		strings/ft_strchr.c \
		strings/ft_strdup.c \
		strings/ft_strlcat.c \
		strings/ft_strlcpy.c \
		strings/ft_strlen.c \
		strings/ft_strncmp.c \
		strings/ft_strnstr.c \
		strings/ft_strrchr.c \
		strings/ft_tolower.c \
		strings/ft_toupper.c \
		strings/ft_substr.c \
		strings/ft_strjoin.c \
		strings/ft_strtrim.c \
		strings/ft_split.c \
		convert/ft_itoa.c \
		strings/ft_strmapi.c \
		strings/ft_striteri.c \
		fd/ft_putchar_fd.c \
		fd/ft_putstr_fd.c \
		fd/ft_putendl_fd.c \
		fd/ft_putnbr_fd.c \
		printf/src/ft_char_manager.c \
		printf/src/ft_condition.c \
		printf/src/ft_hexa_convert.c \
		printf/src/ft_hexa_manager.c \
		printf/src/ft_int_manager.c \
		printf/src/ft_itoa_unsigned.c \
		printf/src/ft_char_manager.c \
		printf/src/ft_printf.c \
		get_next_line/src/get_next_line.c \

SRCSB = linked_list/ft_lstnew_bonus.c \
		linked_list/ft_lstadd_front_bonus.c \
		linked_list/ft_lstsize_bonus.c \
		linked_list/ft_lstlast_bonus.c \
		linked_list/ft_lstadd_back_bonus.c \
		linked_list/ft_lstdelone_bonus.c \
		linked_list/ft_lstclear_bonus.c \
		linked_list/ft_lstiter_bonus.c \
		linked_list/ft_lstmap_bonus.c \

OFILES = $(SRCS:.c=.o)

OBONUS = $(SRCSB:.c=.o)


HEADER = include/%.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER)

NAME = libft.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES) $(OBONUS)

bonus: $(OBONUS) $(OFILES)
	ar rcs $(NAME) $(OFILES) $(OBONUS)


fclean: clean
	rm -f $(NAME) 

re:
	$(MAKE)	fclean
	$(MAKE)	all

.PHONY: all bonus clean fclean re