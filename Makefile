# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:11:05 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/01 23:00:53 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Wextra -Werror
UTILS= utils/ft_printer.c utils/ft_converter.c
NAME= server client
BONUS= server_bonus client_bonus

all: $(NAME)

$(NAME): ft_server.o ft_client.o

ft_server.o: ft_server.c minitalk.h
	cc $(CFLAGS) -c ft_server.c -o ft_server.o
	cc $(CFLAGS) ft_server.o $(UTILS) -o server

ft_client.o: ft_client.c minitalk.h
	cc $(CFLAGS) -c ft_client.c -o ft_client.o
	cc $(CFLAGS) ft_client.o $(UTILS) -o client

ft_server_bonus.o: ft_server_bonus.c minitalk_bonus.h
	cc $(CFLAGS) -c ft_server_bonus.c -o ft_server_bonus.o
	cc $(CFLAGS) ft_server_bonus.o $(UTILS) -o server_bonus

ft_client_bonus.o: ft_client_bonus.c minitalk_bonus.h
	cc $(CFLAGS) -c ft_client_bonus.c -o ft_client_bonus.o
	cc $(CFLAGS) ft_client_bonus.o $(UTILS) -o client_bonus

$(BONUS): ft_server_bonus.o ft_client_bonus.o

bonus: $(BONUS)

clean:
	rm -f ft_server.o ft_client.o ft_server_bonus.o ft_client_bonus.o

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus