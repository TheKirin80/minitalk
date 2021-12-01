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

${NAMESRV}:	${OBJSSRV} 
			${CC}  ${CFLAGS} ${OBJSSRV} -o ${NAMESRV}

#${NAMECLT}:	${OBJSCLT} 
#			${CC}  ${CFLAGS} ${OBJSCLT} -o ${NAMECLT}

bonus:		${OBJS} ${OBJSBON} 
			${CCLIB} ${OBJS} ${OBJSBON}

all:		${NAMESRV}
			#${NAMECLT}

clean:		
			${RM} ${OBJS} ${OBJSBON}

fclean:		clean
			${RM} ${NAME} 

re:			fclean all

.PHONY:		all clean fclean re bonus