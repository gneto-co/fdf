# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gneto-co <gneto-co@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 10:51:25 by gneto-co          #+#    #+#              #
#    Updated: 2024/01/12 15:54:00 by gneto-co         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CONVERSION_FUNCTIONS = $(addprefix conversion_functions/, \
ft_atoi.c \
ft_itoa.c \
)

LIST_FUNCTIONS = $(addprefix list_functions/, \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstdup.c \
)

MATH_FUNCTIONS = $(addprefix math_functions/, \
ft_numlen.c \
ft_numlen_base.c \
op_power_of.c \
)

MEMORY_FUNCTIONS = $(addprefix memory_functions/, \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_calloc.c \
)

PRINT_FUNCTIONS = $(addprefix print_functions/, \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putnbr.c \
ft_putnbr_base.c \
ft_putchar.c \
ft_putstr.c \
ft_putstr_newline.c \
ft_put_unsigned_nbr.c \
ft_putpt.c \
)

READ_FUNCTIONS = $(addprefix read_functions/, \
$(addprefix get_next_line/, \
get_next_line.c \
get_next_line_utils.c ) \
)

STRING_FUNCTIONS = $(addprefix string_functions/, \
ft_strlen.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strncmp.c \
ft_strnstr.c \
ft_split.c \
ft_strdup.c \
ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_strmapi.c \
ft_striteri.c \
ft_multi_strjoin.c \
)

VERIFICATION_FUNCTIONS = $(addprefix verification_functions/, \
ft_isalpha.c \
ft_isdigit.c \
ft_isalnum.c \
ft_isascii.c \
ft_isprint.c \
ft_nb_already_exist.c \
)

SOURCES = \
$(CONVERSION_FUNCTIONS) \
$(LIST_FUNCTIONS) \
$(MATH_FUNCTIONS) \
$(MEMORY_FUNCTIONS) \
$(PRINT_FUNCTIONS) \
$(READ_FUNCTIONS) \
$(STRING_FUNCTIONS) \
$(VERIFICATION_FUNCTIONS) \

OBJECTS = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) 
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)

re: fclean all