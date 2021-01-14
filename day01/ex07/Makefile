NAME=replacer

CPP=clang++
CPP_FLAGS=-Wall -Wextra -Werror

SRC=main.cpp Replacer.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CPP) $(CPP_FLAGS) $^ -o $@ 

%.o: %.cpp
	$(CPP) $(CPP_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all