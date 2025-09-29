
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abisiani <abisiani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/12 15:15:30 by abisiani          #+#    #+#              #
#    Updated: 2025/05/29 14:34:53 by abisiani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

CFLAGS=-I. -Wall -Werror -Wextra

AR=ar rcs

CC=cc

NAME=libft.a

SRC=ft_isalpha.c ft_toupper.c ft_tolower.c ft_isdigit.c ft_isalnum.c\
	ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
	ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_atoi.c\
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c  ft_calloc.c ft_strdup.c\
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c  ft_strmapi.c \
	ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c

BONUS=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJ=$(SRC:.c=.o)

OBJBONUS=$(BONUS:.c=.o)

all: $(NAME)

ifeq ($(BONUSMODE),1)
OBJ_ALL := $(OBJ) $(OBJBONUS)
else
OBJ_ALL := $(OBJ)
endif

$(NAME): $(OBJ_ALL)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

bonus:
	$(MAKE) fclean
	$(MAKE) BONUSMODE=1 all

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# test: re
# 	$(CC) $(CFLAGS) -o libft libft.c -L. -lft -lbsd
# 	./libft
