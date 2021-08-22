.PHONY: all re fclean clean

NAME = deathnote

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror

SOURCES = Contact.cpp Table.cpp Phonebook.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

OBJ_DIR = obj

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(CC) $(CPPFLAGS) $^ -o $@
	@echo "-Hello, Yagami Light, my name is Ryuk."
	@echo "-Since you started makefile you are the holder of the ${NAME}."

%.o : %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf ${OBJECTS}

fclean: clean
	@rm -rf $(NAME)
	@echo "-That was intresting. Goodbye."

re: fclean all