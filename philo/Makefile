NAME	=	philo
CC		=	clang
HEADER	=	includes/philo.h
OBJDIR	=	obj
SRC		=	srcs/philo.c \
			srcs/timeandutils.c \
			srcs/initiators.c \
			srcs/threader.c

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