NAME	= libftprintf.a

SOURCES	= ft_printf.c \
print_c.c \
print_d.c \
print_s.c \
print_u.c \
print_x.c \
print_p.c



OBJECTS	= ${SOURCES:.c=.o}

INCLUDES	= ft_printf.h

CFLAGS	= -Wall -Wextra -Werror

LIBFT_DIR	= ./libft

LIBFT		= $(LIBFT_DIR)/libft.a

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCLUDES}

${NAME}: ${OBJECTS} $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rc ${NAME} ${OBJECTS}
	ranlib ${NAME}

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

all: ${NAME}

clean:
	make -C $(LIBFT_DIR) clean
	rm -f ${OBJECTS}
	make clean -C $(LIBFT_DIR)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f ${NAME}

re: fclean all