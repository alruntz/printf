NAME = libftprintf.a

CC = gcc

SOURCE = ./printf/ft_printf.c ./printf/conversion.c\
		 ./printf/ft_itoa_base.c ./printf/ft_putnbr_base.c  \
		 ./libft/ft_strlen.c \
		 ./libft/ft_strdup.c \
		 ./libft/ft_putchar.c \
		 ./libft/ft_putnbr.c \
		 ./libft/ft_putstr.c \
		 ./libft/ft_strjoin.c \

NOM = $(basename $(SOURCE))

OBJET = $(addsuffix .o, $(NOM))

FLAGS = -Wall -Werror -Wextra -I ./printf -I ./printf/libft/


HEADER = ft_printf.h

all: $(NAME)

$(NAME): $(OBJET)
	make -C ./libft/
	ar -rsc $(NAME) $^

%.o: %.c
	$(CC) -o $@ -c $< $(FLAGS)

clean:
	make -C ./libft/ clean
	/bin/rm -f $(OBJET)

fclean: clean
	make -C ./libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
	echo "re libftprintf OK"

.PHONY: all clean fclean re
