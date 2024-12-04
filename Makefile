# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eunjiko <eunjiko@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 16:06:30 by eunjiko           #+#    #+#              #
#    Updated: 2023/05/01 16:33:41 by eunjiko          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS    = args_check.c check.c init_data.c main.c philo.c pick.c \
			printf.c time.c utils.c
OBJS	= ${SRCS:.c=.o}
CC		= cc
CFLAGS	= -Wall -Werror -Wextra 
NAME    = philo

all:		${NAME}

.c.o:		${SRCS}
			${CC} ${CFLAGS} -c $^ -o ${^:.c=.o}

${NAME}:	${OBJS}
			$(CC) -o $(NAME) ${OBJS}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re