.PHONY: all re fclean clean

NAME = ex00

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

OBJDIR = .obj

HEADERS = easyfind.hpp NotFoundException.hpp
SOURCES = main.cpp NotFoundException.cpp  
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
