.PHONY: all re fclean clean

NAME = replacer

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

OBJDIR = .obj

SOURCES = main.cpp Replacer.cpp IO.cpp Utils.cpp
OBJECTS = $(addprefix ${OBJDIR}/, $(SOURCES:.cpp=.o))

all: objdir $(NAME)

objdir:
	@if ! [ -d ${OBJDIR} ] ; then mkdir ${OBJDIR} ; fi

$(NAME): $(OBJECTS)
	@$(CC) $(CPPFLAGS) $^ -o $@

${OBJDIR}/%.o : %.cpp
	@$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf ${OBJDIR}

fclean: clean
	@rm -rf $(NAME)

re: fclean all
