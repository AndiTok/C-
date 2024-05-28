# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atok <atok@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/21 00:07:48 by atok              #+#    #+#              #
#    Updated: 2023/07/21 00:07:48 by atok             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = horde
CC = g++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INCLUDE)

INCLUDE = ~/Zombie.hpp

SRCS = main.cpp \
		Zombie.cpp \
		zombieHorde.cpp

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