FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g

NAME = FragTrap

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

DSRC = $(addprefix src/, $(SRC))

DOBJ = obj

OBJ = $(addprefix $(DOBJ)/, $(SRC:.cpp=.o))

DEP = $(addprefix $(DOBJ)/, $(SRC:.cpp=.d))

INC = -I ./inc

all: dir $(NAME)

dir:
	mkdir -p $(DOBJ)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME) 

$(DOBJ)/%.o: src/%.cpp Makefile
	c++ $(FLAGS) $(INC) -MMD -o $@ -c $<

-include $(DEP)

clean:
	rm -rf $(DOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclena re
