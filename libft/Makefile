# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amine <amine@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 19:49:33 by amrakouk          #+#    #+#              #
#    Updated: 2026/11/06 08:45:13 by amine            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_isdigit.c ft_strncmp.c ft_bzero.c ft_memset.c\
		ft_putstr_fd.c ft_split.c ft_strlen.c ft_strlcpy.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^
	@echo "libft.a Created successfully"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	@echo "object files deleted"

fclean: clean
	rm -f $(NAME)
	@echo "libft.a deleted"

re: fclean all

.PHONY: all clean fclean re

test: $(NAME)
	@echo "Running libftTester..."
	git clone https://github.com/Tripouille/libftTester.git libfttester || true
	cd libfttester && make m
	cd libfttester && make bonus
	@echo "libftTester finished"

cleantest:
	rm -rf libfttester
	@echo "libfttester deleted"

.PHONY: all clean fclean re bonus test cleantest
