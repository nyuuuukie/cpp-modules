.PHONY: all re fclean clean

NAME = deathnote

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror

OBJDIR = .obj

SOURCES = Contact.cpp Table.cpp Phonebook.cpp Attribute.cpp main.cpp Parse.cpp
OBJECTS = $(addprefix ${OBJDIR}/, $(SOURCES:.cpp=.o))

all: objdir $(NAME)

objdir:
	@if ! [ -d ${OBJDIR} ] ; then mkdir ${OBJDIR} ; fi

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $^ -o $@
	@echo "-Hello, Yagami Light, my name is Ryuk."
	@echo "-Since you started makefile you are the holder of the ${NAME}."

${OBJDIR}/%.o : %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf ${OBJDIR}

fclean: clean
	@rm -rf $(NAME)
	@echo "-That was interesting. Goodbye."

re: fclean all