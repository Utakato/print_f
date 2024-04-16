# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fschipor <fschipor@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 17:14:52 by fschipor          #+#    #+#              #
#    Updated: 2024/03/30 17:08:49 by fschipor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c \
ft_bzero.c \
ft_calloc.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_putchar_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_putstr_fd.c \
ft_split.c \
ft_strchr.c \
ft_strdup.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strlen.c \
ft_strmapi.c \
ft_strncmp.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_substr.c \
ft_tolower.c \
ft_toupper.c


OBJECTS = ${SRC:.c=.o}

FLAGS = -Wall -Wextra -Werror

CC = cc

INCLUDES = ./

${NAME}: ${OBJECTS}
	ar rc ${NAME} ${OBJECTS}
	ranlib ${NAME}

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

all: ${NAME}

clean: 
	rm -rf ${OBJECTS}

test:  
	${CC} ${FLAGS} -g 

fclean: clean
	rm -f ${NAME}

re: fclean all



