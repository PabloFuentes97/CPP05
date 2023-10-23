NAME = Forms

SRC = main.cpp AForm.cpp Bureaucrat.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME) 

CC		= c++

CCFLAGS	= -Wall -Werror -Wextra -std=c++98

$(NAME): $(OBJ)
		$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)
clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re