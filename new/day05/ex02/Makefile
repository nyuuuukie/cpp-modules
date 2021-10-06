.PHONY: all re fclean clean

NAME = ex02

CC = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

OBJDIR = .obj
HEADERS = Bureaucrat.hpp Form.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp ShrubberyCreationForm.hpp
SOURCES = Bureaucrat.cpp Form.cpp main.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp
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
