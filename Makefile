#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 22:59:16 by abisiani          #+#    #+#              #
#    Updated: 2025/09/25 15:42:16 by abisiani         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

.PHONY: all clean fclean re bonus test test_wrap

CFLAGS=-Wall -Werror -Wextra

AR=ar -rcs

CC=cc

NAME=libpushswap.a

EXECUTABLE=push_swap

SRC_DIR = src
SRC_FILES = push_swap.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ=$(SRC:.c=.o)

LIBFT=libft/libft.a

all: $(NAME)

libft/libft.a:
	make -C libft all

$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) .
	@mv libft.a $(NAME)
	$(AR) $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(EXECUTABLE)
	make -C libft fclean

re: fclean all

test: re
	$(CC) -g $(CFLAGS) -o $(EXECUTABLE) src/push_swap.c -L. -lpushswap -Llibft -lft
	./$(EXECUTABLE)

# test_wrap: re
# 	$(CC) -g $(CFLAGS) -rdynamic -Wl,--wrap=malloc -Wl,--wrap=free -o $(EXECUTABLE) push_swap.c $(SRC_FILES)
