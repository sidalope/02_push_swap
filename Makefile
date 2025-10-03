# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisani <abisani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 22:59:16 by abisiani          #+#    #+#              #
#    Updated: 2025/10/03 15:26:36 by abisani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus test test_wrap

CFLAGS=-Wall -Werror -Wextra

AR=ar -rcs

CC=cc

NAME=libpushswap.a

EXECUTABLE=push_swap

SRC_DIR = src

SRC_FILES = push_swap.c

STACK_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c

PRINTF_FILES = intlen.c put_unsnbr_fd.c ft_printf.c print_c.c print_s.c \
	print_p.c print_di.c print_u.c print_x.c print_x_cap.c ft_putnbr_fd.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
	$(addprefix $(SRC_DIR)/stack/, $(STACK_FILES)) \
	$(addprefix $(SRC_DIR)/printf/, $(PRINTF_FILES))

OBJ=$(SRC:.c=.o)

# LIBFT=libft/libft.a

all: $(NAME)

# libft/libft.a:
# 	make -C libft bonus

$(NAME): $(OBJ) #$(LIBFT)
	$(AR) $@ $(OBJ)
# 	@cp $(LIBFT) .
# 	@mv libft.a $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
# 	make -C libft clean

fclean: clean
	rm -f $(NAME) $(EXECUTABLE)
# 	make -C libft fclean

re: fclean all

test: re
	$(CC) -g $(CFLAGS) -o $(EXECUTABLE) src/push_swap.c -L. -lpushswap

test_run: re
	$(CC) -g $(CFLAGS) -o $(EXECUTABLE) src/push_swap.c -L. -lpushswap
	./$(EXECUTABLE)
# -Llibft -lft

# test_wrap: re
# 	$(CC) -g $(CFLAGS) -rdynamic -Wl,--wrap=malloc -Wl,--wrap=free -o $(EXECUTABLE) push_swap.c $(SRC_FILES)
