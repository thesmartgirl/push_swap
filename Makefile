CC              = cc
RM              = rm -rf 
CFLAGS          = -Wall -Werror -Wextra -g
LIB             = -L./libft -lft

SRC             = push_swap.c utils.c opps.c algos.c arg_check.c
OBJ             = $(SRC:.c=.o)

NAME            = push_swap

all: $(NAME)

$(NAME): $(OBJ) 
	$(MAKE) -C ./libft
	$(CC) $(OBJ) $(LIB) -o$(NAME)

clean:
	$(RM) $(OBJ) 
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME) 
	$(MAKE) fclean -C ./libft

re: fclean $(NAME)

.PHONY: all clean fclean re 
