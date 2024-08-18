RED_TEXT = \033[1;31m
GREEN_TEXT = \033[1;32m
YELLOW_TEXT = \033[1;33m
RESET_TEXT = \033[0m

NAME = philo
BONUS = philo_bonusB
R=-fsanitize=thread
CFLAGS = -Wall -Werror -Wextra

M_SOURCES = philos.c philo.c parser1.c threads1.c threads2.c threads3.c
# B_SOURCES = $(wildcard $(ONUS_DIR)/*.c)

M_OBJECTS = $(M_SOURCES:.c=.o)
# B_OBJECTS = $(B_SOURCES:.c=.o)

%.o : %.c philo.h
	@$(CC) $(CFLAGS) -c $< -o $@

# %_bonus.o : %.c $(BONUS_DIR)/philo_bonus.h
# 	@$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME) : $(M_OBJECTS)
	@$(CC) $(CFLAGS) $(M_OBJECTS) -o $(NAME)
	@echo "$(GREEN_TEXT)[the executable created successfully]$(RESET_TEXT)"

# bonus : $(BONUS)

# $(BONUS) : $(B_OBJECTS)
# 	@$(CC) $(CFLAGS) $(B_OBJECTS) -o $(BONUS)
# 	@echo "$(GREEN_TEXT)[the bonus executable created successfully]$(RESET_TEXT)"

clean :
	@rm -rf $(M_OBJECTS)
	@echo "$(RED_TEXT)object files removed successfully$(RESET_TEXT)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED_TEXT)the executable files removed successfully$(RESET_TEXT)"

re : fclean all

.PHONY : all bonus clean fclean re


# t_philo	*change_node(t_mutex *mutex, int i)
# {
# 	t_philo	*new;
	
# 	new = malloc(sizeof(t_philo));
# 	if (!new)
# 		return (NULL);
# 	new->index = i + 1;
# 	pthread_mutex_init(&(new->last_meal_mutex), NULL);
# 	pthread_mutex_init(&(new->meals_n_mutex), NULL);
# 	new->r_fork = &(mutex->mutex);
# 	new->l_fork = &(mutex->next->mutex);
# 	new->meals_n = 0;
# 	mutex = mutex->next;
# 	new->next = NULL;
# 	return (new);
# }

# void	initialze_philo(t_data *st)
# {
# 	t_philo	*philo;
# 	t_philo	*new;
# 	t_philo	*first;
# 	t_mutex	*mutex;
# 	int		i;

# 	i = 0;
# 	philo = NULL;
# 	mutex = st->mutexs;
# 	while (i < st->philo_n)
# 	{
# 		new = change_node(mutex, i);
# 		if (!new)
# 		{
# 			write(2, "malloc error\n", 13);
# 			st->s_philo = NULL;
# 			return ;
# 		}
# 		if (!i)
# 			first = new;
# 		add_back2(&philo, new);
# 		i++;
# 	}
# 	if (new)
# 		new->next = first;
# 	st->s_philo = philo;
# }