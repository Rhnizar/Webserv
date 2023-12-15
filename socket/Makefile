# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrhnizar <rrhnizar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 22:43:24 by rrhnizar          #+#    #+#              #
#    Updated: 2023/12/13 22:56:00 by rrhnizar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Webserv

NAME_SERVER = Server

NAME_CLIENT = Client

# SRCS = Client.cpp Server.cpp

# OBJS = ${SRCS:.cpp=.o}

CXX = c++ 

RFLAG = ${CXX} -Wall -Werror -Wextra -std=c++98

# %.o : %.cpp
# 	${RFLAG} -c $< -o $@

all: ${NAME}

${NAME} : ${OBJ} ${NAME_SERVER}
	${RFLAG} Client.cpp -o ${NAME_CLIENT}

${NAME_SERVER} :
	${RFLAG} Server.cpp -o ${NAME_SERVER}

clean :
	@rm -rf Client Server
	
fclean : clean

re : fclean all