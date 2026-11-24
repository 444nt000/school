# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aradix <444nt000@proton.me>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/10/19 14:00:00 by aradix            #+#    #+#              #
#    Updated: 2026/11/23 15:07:38 by aradix           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

CC				= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I .
AR				= ar rcs

SRCS			= ft_printf.c \
						handlers/handle_char.c \
						handlers/handle_str.c \
						handlers/handle_ptr.c \
						handlers/handle_int.c \
						handlers/handle_uint.c \
						handlers/handle_hex.c \
						handlers/handle_percent.c \
						utils/ft_putnbr_base.c \
						utils/ft_strlen.c \

OBJS			= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
