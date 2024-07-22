# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lkhye-ya <lkhye-ya@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/22 17:26:11 by lkhye-ya          #+#    #+#              #
#    Updated: 2024/07/22 17:26:11 by lkhye-ya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = exe
SRC_DIR = Gameplay
OBJ_DIR = Obj
FILES = gameplay
SRC = $(foreach file, $(FILES), $(SRC_DIR)/$(file).cpp)
OBJ = $(foreach file, $(FILES), $(OBJ_DIR)/$(file).o)
INC = -I Header
CC = G++
CFLAGS = -std=c++17

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ)


all:$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean
