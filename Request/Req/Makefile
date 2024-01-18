# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/18 19:42:29 by rrhnizar          #+#    #+#              #
#    Updated: 2024/01/18 19:50:42 by rrhnizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Web_serv

RFLAG = c++ -Wall -Werror -Wextra -std=c++98

SRCS = Request.cpp Response.cpp Parse_Request.cpp

OBJS = ${SRCS:.cpp=.o}

%.o : %.cpp
	${RFLAG} -c $< -o $@

all: ${NAME}

${NAME} : ${OBJS}
	${RFLAG} ${OBJS} -o ${NAME}


clean :
	@rm -rf ${OBJS}
	
fclean : clean
	@rm -rf ${NAME}

re : fclean all
