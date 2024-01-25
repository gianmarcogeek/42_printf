# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpuscedd <gpuscedd@student.42roma.it>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 20:28:24 by gpuscedd          #+#    #+#              #
#    Updated: 2024/01/25 21:02:19 by gpuscedd         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIBFT_DIR = ./libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c


$(NAME): $(LIBFT_DIR)/libft.a 
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft

$(LIBFT_DIR)/libft.a:
	@$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
