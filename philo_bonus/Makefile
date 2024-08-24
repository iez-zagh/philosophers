RED_TEXT = \033[1;31m
GREEN_TEXT = \033[1;32m
YELLOW_TEXT = \033[1;33m
RESET_TEXT = \033[0m

NAME = philo_bonus
CFLAGS = -Wall -Werror -Wextra
CC=cc
M_SOURCES = philos_bonus.c philo_bonus.c parser1_bonus.c pro1_bonus.c pro2_bonus.c pro3_bonus.c ft_free_bonus.c

M_OBJECTS = $(M_SOURCES:.c=.o)

%.o : %.c philo_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)
$(NAME) : $(M_OBJECTS)
	$(CC) $(CFLAGS) $(M_OBJECTS) -o $(NAME)
	@echo "$(GREEN_TEXT)[the executable created successfully]$(RESET_TEXT)"

clean :
	@rm -rf $(M_OBJECTS)
	@echo "$(RED_TEXT)object files removed successfully$(RESET_TEXT)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED_TEXT)the executable files removed successfully$(RESET_TEXT)"

re : fclean all

.PHONY : clean
