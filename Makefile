RED_TEXT =\033[1;31m
GREEN_TEXT =\033[1;32m
YELLOW_TEXT =\033[1;33m
RESET_TEXT =\033[0m

NAME = philo
BONUS = philo_bonus
CFLAGS = -Wall -Werror -Wextra
CC = CC
MANDATORY_DIR = philo
BONUS_DIR = philo_bonus

M_SOURCES = $(wildcard $(MANDATORY_DIR)/*.c)
B_SOURCES = $(wildcard $(BONUS_DIR)/*_bonus.c)

M_OBJECTS = ${M_SOURCES:.c=.o}
B_OBJECTS = ${B_SOURCES:.c=.o}

%.o : %.c $(MANDATORY_DIR)/philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o : %_bonus.c $(BONUS_DIR)/philo_bonus.h
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(M_OBJECTS)
	@$(CC) $(CFLAGS) $(M_OBJECTS) -o $(NAME)
	@echo "$(GREEN_TEXT)[the executable created successfully]$(RESET_TEXT)"

bonus : $(BONUS)

$(BONUS) : $(B_OBJECTS)
	@$(CC) $(CFLAGS) $(B_OBJECTS) -o $(BONUS)
	@echo "$(GREEN_TEXT)[the executable created successfully]$(RESET_TEXT)"

clean :
	@rm -rf $(M_OBJECTS)
	@rm -rf $(B_OBJECTS)
	@echo "$(RED_TEXT)object files removed successfully$(RESET_TEXT)"
fclean : clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@echo "$(RED_TEXT)the executable files removed successfully$(RESET_TEXT)"

re : fclean all

.PHONY : clean