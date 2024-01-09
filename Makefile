# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/14 14:11:05 by mait-elk          #+#    #+#              #
#    Updated: 2024/01/09 13:33:47 by mait-elk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS= -Wall -Wextra -Werror
UTILS= utils/ft_printer.c utils/ft_utils.c
NAME= server client
BONUS= server_bonus client_bonus

all: $(NAME)
	@echo "\033[42mCOMPILING COMPLETED.\033[0m"

$(NAME): ft_server.o ft_client.o

ft_server.o: ft_server.c minitalk.h
	@echo "\033[44mCOMPILING SERVER FILES...\033[0m"
	@cc $(CFLAGS) -c ft_server.c -o ft_server.o
	@cc $(CFLAGS) ft_server.o $(UTILS) -o server

ft_client.o: ft_client.c minitalk.h
	@echo "\033[44mCOMPILING CLIENT FILES...\033[0m"
	@cc $(CFLAGS) -c ft_client.c -o ft_client.o
	@cc $(CFLAGS) ft_client.o $(UTILS) -o client

ft_server_bonus.o: ft_server_bonus.c minitalk_bonus.h
	@echo "\033[44mCOMPILING BONUS SERVER FILES...\033[0m"
	@cc $(CFLAGS) -c ft_server_bonus.c -o ft_server_bonus.o
	@cc $(CFLAGS) ft_server_bonus.o $(UTILS) -o server_bonus

ft_client_bonus.o: ft_client_bonus.c minitalk_bonus.h
	@echo "\033[44mCOMPILING BONUS CLIENT FILES...\033[0m"
	@cc $(CFLAGS) -c ft_client_bonus.c -o ft_client_bonus.o
	@cc $(CFLAGS) ft_client_bonus.o $(UTILS) -o client_bonus

$(BONUS): ft_server_bonus.o ft_client_bonus.o

bonus: $(BONUS)
	@echo "\033[42mCOMPILING BONUS COMPLETED.\033[0m"

clean:
	@rm -f ft_server.o ft_client.o ft_server_bonus.o ft_client_bonus.o
	@echo "\033[44mDELETING OBJECT FILES...\033[0m"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@echo "\033[44mDELETING EXE FILES...\033[0m"

re: fclean all

.PHONY: all clean fclean re bonus