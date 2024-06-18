SRC =  main.cpp Shteiner.cpp Filereader.cpp Fillfile.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Shteiner

LIB = visual/so_long

CC = clang++

FLAGS = -Wall -Werror -Wextra -std=c++98 -W

all:	$(NAME) visual

visual:	
			@make -C visual/

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)
			@make -C visual/ 

%.o:		%.c 
			$(CC) $(FLAGS)  -c $< -o $@ -I $(INCLUDE)


clean:			
				@rm -rf $(OBJ) $(OBJ_B)
				make -C visual/ clean

fclean:			clean
				@make -C visual/ fclean
				rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean rev sl