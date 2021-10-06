.PHONY: all re fclean clean

NAME = ex02

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wno-unused-variable

OBJDIR = .obj
HEADERS = A.hpp B.hpp C.hpp Base.hpp            
SOURCES = A.cpp B.cpp C.cpp Base.cpp main.cpp generate.cpp identify.cpp
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
