# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakeFile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atok <atok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 00:44:01 by atok              #+#    #+#              #
#    Updated: 2024/04/29 00:44:01 by atok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex00
CC = g++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRCS = main.cpp ScalarConverter.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
