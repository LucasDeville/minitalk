MAKEFLAGS += --silent
CC = cc
PRINTF_PATH = ft_printf/
LIB = -L${PRINTF_PATH} -lftprintf
PRINTF = ft_printf/libftprintf.a
CFLAGS = -Wall -Wextra -Werror
SRCS_C = client.c
SRCS_S = server.c
OBJS_CLIENT = ${SRCS_C:.c=.o}
OBJS_SERVER = ${SRCS_S:.c=.o}
CLIENT = client
SERVER = server

all: ${PRINTF} ${CLIENT} ${SERVER}
	echo "\033[7;32m~| Tous les fichiers sont à jour ! |~\033[0m"\

${PRINTF}:
	@make -sC ${PRINTF_PATH} all

${CLIENT}:${OBJS_CLIENT}
	${CC} ${CFLAGS} ${OBJS_CLIENT} ${LIB} -o ${CLIENT} \
		&& echo "\033[1;32m~| Compilation du $@ : OK |~\033[0m"\
		|| echo "\033[1;31m~| Compilation du $@ : Erreur |~\033[0m"

${SERVER}:${OBJS_SERVER}
	${CC} ${CFLAGS} ${OBJS_SERVER} ${LIB} -o ${SERVER} \
		&& echo "\033[1;32m~| Compilation du $@ : OK |~\033[0m"\
		|| echo "\033[1;31m~| Compilation du $@ : Erreur |~\033[0m"

clean:
	make -sC ${PRINTF_PATH} fclean
	rm -f ${OBJS_CLIENT} ${OBJS_SERVER}\
		&& echo "\033[1;33m~| Nettoyage des .o : OK |~\033[0m"\
		|| echo "\033[0;31m~| Compilation du $@ : Erreur |~\033[0m"

fclean: clean
	rm -f ${CLIENT} ${SERVER} \
		&& echo "\033[1;33m~| Nettoyage des executables : OK |~\033[0m"\
		|| echo "\033[0;31m~| Compilation du $@ : Erreur |~\033[0m"

re: fclean all
