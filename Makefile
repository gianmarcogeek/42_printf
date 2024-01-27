# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 12:27:35 by gpuscedd          #+#    #+#              #
#    Updated: 2024/01/27 20:15:09 by gpuscedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS			=	ft_putchar_fd.c ft_putnbr_fd.c \
					ft_putstr_fd.c ft_putnbr_base.c \
					ft_printf.c ft_putptr.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< 

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
