# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:51:25 by gneto-co          #+#    #+#              #
#    Updated: 2024/02/02 11:31:48 by gneto-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a

PROJECT_SOURCES = $(addsuffix .c, \
fdf \
map_reader \
$(addprefix window_functions/, \
pw \
render_functions \
lines_test \
mlx_utils \
handle_functions \
pw_operations \
drawn_map \
) \
)

SOURCES = $(PROJECT_SOURCES)
	
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) 
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all