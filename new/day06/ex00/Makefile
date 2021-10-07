.PHONY: all re fclean clean

NAME = convert

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wno-unused-parameter -g

OBJDIR = .obj
HEADERS = Parse.hpp      
SOURCES = main.cpp Parse.cpp
OBJECTS = $(addprefix ${OBJDIR}/, $(SOURCES:.cpp=.o))

all: objdir $(NAME)

objdir:
	@if ! [ -d ${OBJDIR} ] ; then mkdir ${OBJDIR} ; fi

$(NAME): $(OBJECTS)
	$(CC) $(CPPFLAGS) $^ -o $@

${OBJDIR}/%.o : %.cpp ${HEADERS}
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf ${OBJDIR}
	@rm -f *_shrubbery

fclean: clean
	@rm -rf $(NAME)

re: fclean all
