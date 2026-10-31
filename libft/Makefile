# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amrakouk <amrakouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/10 19:49:33 by amrakouk          #+#    #+#              #
#    Updated: 2025/11/16 16:15:03 by amrakouk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  ft_atoi.c ft_isdigit.c ft_memmove.c ft_strchr.c ft_strncmp.c\
		ft_toupper.c ft_bzero.c ft_isprint.c ft_memset.c ft_strdup.c\
		ft_strnstr.c ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strjoin.c\
		ft_strrchr.c ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_strlcat.c\
		ft_strtrim.c ft_isalpha.c ft_memcmp.c ft_putstr_fd.c ft_strlcpy.c\
		ft_substr.c ft_isascii.c ft_memcpy.c ft_split.c ft_strlen.c\
		ft_tolower.c ft_putnbr_fd.c ft_strmapi.c ft_striteri.c 

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
		ft_lstmap.c
		
OBJS = $(SRCS:.c=.o) $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^
	@echo "libft.a Created successfully"

bonus: $(OBJS)
	ar rcs $(NAME) $^
	@echo "libft.a with bonus created"

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
