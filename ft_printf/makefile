SRCS	= ft_printf.c ft_modif.c ft_modif_tool.c ft_modif_tool2.c ft_insert.c ft_libft_first.c ft_libft_third.c ft_rempli_objet.c ft_libft_second.c 

SRCSBON	=

INC		= -I includes

OBJS	= ${SRCS:.c=.o}

OBJSBON	= ${SRCSBON:.c=.o}

NAME 	= libftprintf.a

CC 		= gcc

CCLIB	= ar rcs

RM 		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o :
			${CC} ${CFLAGS} ${INC} -o $@ -c $<

${NAME}:	${OBJS} ft_printf.h
			${CCLIB} libftprintf.a ${OBJS}

bonus:		${OBJS} ${OBJSBON} ft_printf.h
			${CCLIB} libftprintf.a ${OBJS} ${OBJSBON}

all:		${NAME}

clean:		
			${RM} ${OBJS} ${OBJSBON}

fclean:		clean
			${RM} ${NAME} 

re:			fclean all

.PHONY:		all clean fclean re bonus