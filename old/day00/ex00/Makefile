.PHONY: all re fclean clean

NAME = megaphone

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror

SOURCES = megaphone.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CPPFLAGS) $^ -o $@
	@echo "-Are you ready to shout?"
%.o : %.cpp
	@$(CC) $(CPPFLAGS) -c $(SOURCES)

clean:
	@rm -rf $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@echo "Hey, you! Get my megaphone back!"

re: fclean all
