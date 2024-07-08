NAME := pipex
SRCS := src/pipex.c \
libft/libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

all: $(NAME)

$(NAME): $(SRCS)
	@make all -C libft
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft

clean:
	@make clean -C libft

re: fclean all

.PHONY: all fclean clean re