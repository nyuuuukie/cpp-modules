.PHONY: all re fclean clean

NAME = phonebook

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror

SOURCES = Contact.class.cpp Table.class.cpp phonebook.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CPPFLAGS) -c $(SOURCES)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
