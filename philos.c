#include "philo.h"

t_philo	*get_last(t_philo *philo)
{
	if (!philo)
		return (NULL);
	while (philo->next)
		philo = philo->next;
	return (philo);
}

void	add_back(t_philo **philo, t_philo *new)
{
	if (!*philo)
		*philo = new;
	else
	{
		get_last(*philo)->next = new;
		new->next = NULL;
	}
}

void	initialze_philo(t_data *st)
{
	t_philo	*philo;
	t_philo	*new;
	t_mutex	*mutex;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	mutex = st->mutexs;
	while (i < st->philo_n)
	{
		new = malloc(sizeof(t_philo));//protection
		new->index = i;
		new->l_fork = mutex->mutex;
		new->r_fork = mutex->next->mutex;
		add_back(&philo, new);
		mutex = mutex->next;
		i++;
	}
	st->s_philo = philo;
}
