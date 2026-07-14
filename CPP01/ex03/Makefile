# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 15:55:02 by nchairun          #+#    #+#              #
#    Updated: 2025/11/01 18:23:22 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

NAME    = unnecessary_violence

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRCS    = main.cpp $(SRC_DIR)/Weapon.cpp $(SRC_DIR)/HumanA.cpp $(SRC_DIR)/HumanB.cpp

OBJS    = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.cpp=.o)))

.SILENT:
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

$(OBJ_DIR)/main.o: main.cpp
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re