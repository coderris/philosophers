# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 23:39:17 by lanton-m          #+#    #+#              #
#    Updated: 2025/10/03 23:39:17 by lanton-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror -pthread

SRCS_DIR = srcs/
INCLUDE_DIR = include/
OBJS_DIR = objs/

SRCS = 	$(SRCS_DIR)philosophers.c \
		$(SRCS_DIR)utils.c \
		$(SRCS_DIR)parser.c \
		$(SRCS_DIR)time.c \
		$(SRCS_DIR)rutine.c \
		$(SRCS_DIR)monitor.c \
		$(SRCS_DIR)cleaners.c \

OBJS = $(SRCS:$(SRCS_DIR)%.c=$(OBJS_DIR)%.o)

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(COMPILER) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(COMPILER) $(CFLAGS) -I$(INCLUDE_DIR) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS_DIR)		

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re