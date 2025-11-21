# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisani <abisani@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/07 22:59:16 by abisiani          #+#    #+#              #
#    Updated: 2025/11/21 22:16:57 by abisani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus test unit_tests

CFLAGS = -Wall -Werror -Wextra

AR = ar -rcs

CC = cc

NAME = push_swap
LIB_NAME = libpushswap.a

SRC_DIR = src

MAIN_SRC_FILES = main.c
LIB_SRC_FILES = init.c

CHUNK_SORT_FILES = chunk_sort.c chunk_split.c chunk_merge.c \
	chunk_merge_execute.c chunk_merge_utils.c

LIST_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstpop.c \
	ft_lstclear.c ft_lstiter.c

LIST_UTILS_FILES = push.c rotate.c swap.c print_content.c is_sorted.c

OPTIMISER_FILES = log.c naive_optimisation.c utils.c

PRINTF_FILES = intlen.c put_unsnbr_fd.c ft_printf.c print_c.c print_s.c \
	print_p.c print_di.c print_u.c print_x.c print_x_cap.c ft_putnbr_fd.c

UTILS_FILES = ft_atoi.c ft_isnumber.c  ps_error.c ft_strncmp.c \
	ft_strjoin.c ft_strlen.c max.c

MAIN_SRC = $(addprefix $(SRC_DIR)/, $(MAIN_SRC_FILES))
LIB_SRC = $(addprefix $(SRC_DIR)/, $(LIB_SRC_FILES)) \
	$(addprefix $(SRC_DIR)/, $(CHUNK_SORT_FILES)) \
	$(addprefix $(SRC_DIR)/utils/, $(UTILS_FILES)) \
	$(addprefix $(SRC_DIR)/cd_linked_list/list_utils/, $(LIST_UTILS_FILES)) \
	$(addprefix $(SRC_DIR)/cd_linked_list/, $(LIST_FILES)) \
	$(addprefix $(SRC_DIR)/op_optimiser/, $(OPTIMISER_FILES)) \
	$(addprefix $(SRC_DIR)/printf/, $(PRINTF_FILES))

MAIN_OBJ = $(MAIN_SRC:.c=.o)
LIB_OBJ = $(LIB_SRC:.c=.o)

all: $(NAME)

$(LIB_NAME): $(LIB_OBJ)
	$(AR) $@ $(LIB_OBJ)

$(NAME): $(MAIN_OBJ) $(LIB_NAME)
	$(CC) $(CFLAGS) -g -o $(NAME) $(MAIN_OBJ) -L. -lpushswap

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	rm -f $(LIB_OBJ) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME) $(LIB_NAME) $(NAME)_unit_test $(NAME)_memory_test

re: fclean all

test: re
	./tests/tests.sh

test_chunk: re
	./push_swap $$(cat tests/random_100.txt)

unit_tests: $(LIB_NAME) tests/unit_tests.c
	$(CC) -g $(CFLAGS) -o $(NAME)_unit_test tests/unit_tests.c -L. -lpushswap
	./$(NAME)_unit_test $$(cat tests/random_100.txt) 2>&1
