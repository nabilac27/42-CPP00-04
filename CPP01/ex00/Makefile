# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nchairun <nchairun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/31 19:18:27 by nchairun          #+#    #+#              #
#    Updated: 2025/11/02 16:14:08 by nchairun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

NAME    = zombie

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

SRCS    = main.cpp \
          $(SRC_DIR)/Zombie.cpp $(SRC_DIR)/randomChump.cpp $(SRC_DIR)/newZombie.cpp


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