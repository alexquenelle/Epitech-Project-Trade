##
## EPITECH PROJECT, 2021
## B-CNA-410-BDX-4-1-trade-alexandre.quenelle
## File description:
## Makefile
##

MAIN	=	main.cpp

SRC		=	src/Settings.cpp	\
			src/Crypto.cpp		\
			src/manager.cpp		\
			src/Indicators.cpp		\
			src/Strategie.cpp

OBJ	=	$(SRC:.cpp=.o) $(MAIN:.cpp=.o)

NAME	=	trade

CPPFLAGS	=	-I./include

#-Wall -Wextra

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all