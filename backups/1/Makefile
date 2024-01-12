# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/15 10:09:55 by gabriel           #+#    #+#              #
#    Updated: 2024/01/12 15:47:15 by gneto-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#--------------------------------------------------------------------------------
#-----------------------------LIBFT SOURCE FILES---------------------------------
#--------------------------------------------------------------------------------

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) --no-print-directory


#--------------------------------------------------------------------------------
#----------------------------PROJECT SOURCE FILES--------------------------------
#--------------------------------------------------------------------------------

NAME = fdf

PROJECT_PATH = ./$(NAME)_files

PROJECT = $(PROJECT_PATH)/$(NAME).a

$(PROJECT):
	@$(MAKE) -C $(PROJECT_PATH) --no-print-directory

	
#--------------------------------------------------------------------------------
#-----------------------------------MAIN FILES-----------------------------------
#--------------------------------------------------------------------------------

MAINSOURCES = \
main.c

SOURCES = $(MAINSOURCES)

MAIN = $(SOURCES:.c=.o)


#--------------------------------------------------------------------------------
#--------------------------COMPILATION SPECIFICATIONS----------------------------
#--------------------------------------------------------------------------------

CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_PATH) -I$(PROJECT_PATH) -fsanitize=address


#--------------------------------------------------------------------------------
#---------------------------------MAKEFILE RULES---------------------------------
#--------------------------------------------------------------------------------

.DEFAULT_GOAL := all

all: $(NAME)

$(NAME): $(MAIN) $(PROJECT) $(LIBFT)
	clang $(CFLAGS) -o $(NAME) $(MAIN) $(PROJECT) $(LIBFT)
	@clear
	@echo "\033[32m\n---------- $(NAME) compiled and ready! ----------\033[0m"

clean:
	@rm -f $(MAIN) $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) clean --no-print-directory
	@$(MAKE) -C $(PROJECT_PATH) clean --no-print-directory
	@clear
	@echo "\033[31m\033[33m\n---------- program objects cleaned ----------\033[0m"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean --no-print-directory
	@$(MAKE) -C $(PROJECT_PATH) fclean --no-print-directory
	@clear
	@echo "\033[31m\033[33m\n--------- program name and objects cleaned ----------\033[0m"
	
re: fclean all
