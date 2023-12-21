# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:11:05 by mait-elk          #+#    #+#              #
#    Updated: 2023/12/21 18:22:33 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Wextra -Werror
UTILS= utils/ft_printer.c utils/ft_converter.c
UTILS_O= $(UTILS:.c=.o)
NAME= server client

all: $(NAME)

$(NAME): $(UTILS_O)
	cc $(CFLAGS) ft_server.c $(UTILS_O) -o server
	cc $(CFLAGS) ft_client.c $(UTILS_O) -o client

%.o: %.c minitalk.h
	cc $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(UTILS_O)

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all bonus clean fclean re