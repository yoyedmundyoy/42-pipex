NAME := pipex
LIBFT := libft/libft.a
SRCS := src/pipex.c $(LIBFT)
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf
SRCS_BONUS := src_bonus/pipex_bonus.c $(LIBFT)

all: $(NAME)

bonus: fclean $(SRCS_BONUS)
	@$(CC) $(CFLAGS) $(SRCS_BONUS) -o $(NAME)

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