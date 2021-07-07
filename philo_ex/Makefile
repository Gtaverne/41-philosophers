NAME	=	philo
CC		=	clang
HEADER	=	includes/philo.h
OBJDIR	=	obj
SRC		=	srcs/main.c \
			srcs/utils.c \
			srcs/utils2.c \
			srcs/utils3.c

OBJ 	=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

all: $(NAME)

bonus: all

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re bonus