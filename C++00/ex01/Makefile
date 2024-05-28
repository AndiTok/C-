# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atok <atok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/13 07:45:41 by atok              #+#    #+#              #
#    Updated: 2023/07/13 07:45:41 by atok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex01
CC = g++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INCLUDE)

INCLUDE = ~/ex01.hpp

SRCS = main.cpp \
		add.cpp \
		search.cpp

#OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): #$(OBJS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

# %.o: %.cpp
# 	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re