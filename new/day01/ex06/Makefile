.PHONY: all re fclean clean

NAME = karenFilter

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

OBJDIR = .obj

HEADERS = Karen.hpp
SOURCES = main.cpp Karen.cpp
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

fclean: clean
	@rm -rf $(NAME)

re: fclean all
