SRCSSRV	= main_srv.c 

SRCSCLT	= main_clt.c

INC		= -I includes

OBJSSRV	= ${SRCSSRV:.c=.o}

OBJSCLT	= ${SRCSCLT:.c=.o}

NAMESRV	= server

NAMECLT = client

CC 		= gcc

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o :
			${CC} ${CFLAGS} ${INC} -o $@ -c $<

all:		${NAMECLT} ${NAMESRV}

${NAMECLT}:	${OBJSCLT} 
			${CC}  ${CFLAGS} ${OBJSCLT} -o ${NAMECLT}

${NAMESRV}:	${OBJSSRV} 
			${CC}  ${CFLAGS} ${OBJSSRV} -o ${NAMESRV}

clean:		
			${RM} ${OBJSSRV} ${OBJSCLT}

fclean:		clean
			${RM} ${NAMESRV} ${NAMECLT} 

re:			fclean all

.PHONY:		all clean fclean re bonus