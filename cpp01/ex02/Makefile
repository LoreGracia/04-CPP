FLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -g

NAME = Brain

SRC = main.cpp

DSRC = $(addprefix src/, $(SRC))

DOBJ = obj

OBJ = $(addprefix $(DOBJ)/, $(SRC:.cpp=.o))

DEP = $(addprefix $(DOBJ)/, $(SRC:.cpp=.d))

all: dir $(NAME)

dir:
	mkdir -p $(DOBJ)

$(NAME): $(OBJ)
	c++ $(FLAGS) $(OBJ) -o $(NAME) 

$(DOBJ)/%.o: src/%.cpp Makefile
	c++ $(FLAGS) -MMD -o $@ -c $<

-include $(DEP)

clean:
	rm -rf $(DOBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclena re
