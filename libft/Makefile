# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aradix <444nt000@proton.me>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/19 14:00:00 by aradix            #+#    #+#              #
#    Updated: 2026/11/03 16:40:01 by aradix           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

CC			= cc
CFLAGS	= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f

SRCS		= ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_strlen.c \
			  ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_strlcpy.c \
			  ft_strlcat.c \
			  ft_toupper.c \
			  ft_tolower.c \
			  ft_strchr.c \
			  ft_strrchr.c \
			  ft_strncmp.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_strnstr.c \
			  ft_atoi.c \
			  ft_calloc.c \
			  ft_strdup.c \
			  ft_substr.c \
			  ft_strjoin.c \
			  ft_strtrim.c \
			  ft_split.c \
			  ft_itoa.c \
			  ft_strmapi.c \
			  ft_striteri.c \
			  ft_putchar_fd.c \
			  ft_putstr_fd.c \
			  ft_putendl_fd.c \
			  ft_putnbr_fd.c \
			  ft_lstnew.c \
			  ft_lstadd_front.c \
			  ft_lstsize.c \
			  ft_lstlast.c \
			  ft_lstadd_back.c \
			  ft_lstdelone.c \
			  ft_lstclear.c \
			  ft_lstiter.c \
			  ft_lstmap.c

OBJS		= $(SRCS:.c=.o)

TEST_DIR	= tests
TEST_SRCS	= $(wildcard $(TEST_DIR)/test_*.c)
TEST_BINS	= $(TEST_SRCS:.c=)
SAN_BIN		= $(TEST_DIR)/san_bin
SANFLAGS	= -fsanitize=address,undefined -fno-sanitize-recover=undefined -g

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_DIR)/test_%: $(TEST_DIR)/test_%.c $(TEST_DIR)/check.h $(NAME)
	$(CC) $(CFLAGS) $< $(NAME) -o $@

test: $(TEST_BINS)
	@fail=0; for t in $(TEST_BINS); do ./$$t || fail=1; done; exit $$fail

san:
	@fail=0; for t in $(TEST_SRCS); do \
		$(CC) $(CFLAGS) $(SANFLAGS) $$t $(SRCS) -o $(SAN_BIN) \
		&& ./$(SAN_BIN) || fail=1; \
	done; $(RM) $(SAN_BIN); exit $$fail

norm:
	@norminette $(SRCS) libft.h

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(TEST_BINS) $(SAN_BIN)

re: fclean all

.PHONY: all test san norm clean fclean re
