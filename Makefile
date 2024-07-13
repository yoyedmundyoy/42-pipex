NAME := pipex
LIBFT := libft/libft.a
SRCS := src/pipex.c $(LIBFT)
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

$(LIBFT):
	@make all -C libft

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft

clean:
	@make clean -C libft

re: fclean all

.PHONY: all fclean clean re