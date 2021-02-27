.PHONY: all re fclean clean

NAME = phonebook

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror

SOURCES = Contact.cpp Table.cpp Phonebook.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

OBJ_DIR = obj

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CPPFLAGS) $^ -o $@
	@echo "${NAME} created"

%.o : %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf ${OBJECTS}

fclean: clean
	@rm -rf $(NAME)
	@echo "${NAME} deleted"

re: fclean all