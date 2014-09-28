##
## Makefile for adc in /home/jaccar_a/Documents/ProjEpitech/adc/script
## 
## Made by Quentin Jaccarino
## Login   <jaccar_a@epitech.net>
## 
## Started on  Sun Sep 28 22:17:41 2014 Quentin Jaccarino
## Last update Sun Sep 28 22:22:33 2014 Quentin Jaccarino
##

NAME=		adc

SRC=		src/main.cpp \

OBJ=		$(SRC:.cpp=.o)

CXXFLAGS=	-W -Wall -Wextra -Iinc/

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re