#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 22:59:16 by abisiani          #+#    #+#              #
#    Updated: 2025/10/09 16:51:17 by abisiani         ###   ########.fr        #
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

LIST_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

LIST_UTILS_FILES = push.c rotate.c swap.c del.c print_content.c

PRINTF_FILES = intlen.c put_unsnbr_fd.c ft_printf.c print_c.c print_s.c \
	print_p.c print_di.c print_u.c print_x.c print_x_cap.c ft_putnbr_fd.c

UTILS_FILES = ft_atoi.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
	$(addprefix $(SRC_DIR)/cd_linked_list/, $(LIST_FILES)) \
	$(addprefix $(SRC_DIR)/cd_linked_list/list_utils/, $(LIST_UTILS_FILES)) \
	$(addprefix $(SRC_DIR)/printf/, $(PRINTF_FILES)) \
	$(addprefix $(SRC_DIR)/utils/, $(UTILS_FILES)) \

OBJ=$(SRC:.c=.o)

all: $(NAME) $(EXECUTABLE)

$(EXECUTABLE): $(NAME) $(SRC_DIR)/$(SRC_FILES)
	$(CC) -g $(CFLAGS) -o $(EXECUTABLE) $(SRC_DIR)/$(SRC_FILES) -L. -lpushswap

$(NAME): $(OBJ)
	$(AR) $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(EXECUTABLE)

re: fclean all

test: re
	./tests/tests.sh

unit_tests: fclean $(NAME)
	$(CC) -g $(CFLAGS) -o test_$(EXECUTABLE) tests/unit_tests.c -L. -lpushswap
	./test_$(EXECUTABLE) $$(cat tests/random_10.txt)

test_wrap: re
	$(CC) -g $(CFLAGS) -rdynamic -Wl,--wrap=malloc -Wl,--wrap=free -o $(EXECUTABLE) push_swap.c $(SRC_FILES)
