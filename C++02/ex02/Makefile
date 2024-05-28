# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atok <atok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/15 20:13:38 by atok              #+#    #+#              #
#    Updated: 2023/08/15 20:13:38 by atok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex02
CC = g++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp Fixed.cpp 

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