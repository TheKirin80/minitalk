SRCSSRV	= main_srv.c 

SRCSCLT	= main_clt.c 

SRCSTOOL = tool.c tool_2.c tool_3.c

INC		= -I includes

OBJSSRV	= ${SRCSSRV:.c=.o}

OBJSCLT	= ${SRCSCLT:.c=.o}

OBJSTOOL	= ${SRCSTOOL:.c=.o}

NAMESRV	= server

NAMECLT = client

CC 		= gcc

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror #-fsanitize=address -g3

.c.o :
			${CC} ${CFLAGS} ${INC} -o $@ -c $<

all:		${NAMECLT} ${NAMESRV} 

${NAMECLT}:	${OBJSCLT} ${OBJSTOOL}
			${CC}  ${CFLAGS} ${OBJSCLT} ${OBJSTOOL} -o ${NAMECLT}

${NAMESRV}:	${OBJSSRV} 
			${CC}  ${CFLAGS} ${OBJSSRV} ${OBJSTOOL} -o ${NAMESRV}

clean:		
			${RM} ${OBJSSRV} ${OBJSCLT} ${OBJSTOOL}

fclean:		clean
			${RM} ${NAMESRV} ${NAMECLT} 

re:			fclean all

.PHONY:		all clean fclean re bonus