# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atok <atok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 12:26:39 by atok              #+#    #+#              #
#    Updated: 2023/08/16 12:27:27 by atok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02
CC = g++
FLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRCS = Account.cpp tests.cpp

OBJS = $(SRCS:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
