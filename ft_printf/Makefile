HEADER = ./

FILES_C = ft_printf.c \
	  ft_print.c \
	  ft_hexa.c \

FILES_O = ${FILES_C:.c=.o}
LIBFT_PATH = libft/
LIBFT = libft/libft.a

FILES_H = ${HEADER}ft_printf.h

FLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

all: ${LIBFT} ${NAME}

.c.o:
	gcc ${FLAGS} -I ${HEADER} -c $< -o ${<:.c=.o}

${LIBFT}:
	make -C ${LIBFT_PATH} all bonus

${NAME}: ${FILES_O}
	cp ${LIBFT} .
	mv libft.a ${NAME}
	ar -rc ${NAME} ${FILES_O}

clean:
	make -C ${LIBFT_PATH} fclean
	rm -f ${FILES_O}

fclean: clean
	rm -f ${NAME}

re: fclean all

