/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 13:03:07 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/17 17:16:44 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_mutex	*get_last(t_mutex *philo)
{
	if (!philo)
		return (NULL);
	while (philo->next)
		philo = philo->next;
	return (philo);
}

void	add_back(t_mutex **philo, t_mutex *new)
{
	if (!*philo)
		*philo = new;
	else
	{
		get_last(*philo)->next = new;
		new->next = NULL;
	}
}

t_mutex *create_mutex(int i)
{
	int		j;
	t_mutex	*mutex1;
	t_mutex	*new;

	j = 0;
	mutex1 = NULL;
	while (j < i)
	{
		new = malloc(sizeof(t_mutex));
		pthread_mutex_init(&(new->mutex), NULL);
		new->next = NULL;
		add_back(&mutex1, new);
		j++;
	}
	return (mutex1);
}

t_philo	*get_node(t_philo *philo,  t_data *st)
{
	int			j;

	pthread_mutex_lock(&(st->var_mutex));
	j = 0;
	while (j < st->index)
	{
		philo = philo->next;
		j++;
	}
	st->index++;
	pthread_mutex_unlock(&(st->var_mutex));
	return (philo);

}



#include <unistd.h>

void	putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	putnbr(long long n)
{
	char	c;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	print_message(long long time_diff, int philo_index, char *msg)
{
	putnbr(time_diff);
	write(1, "  ", 2);
	putnbr(philo_index);
	write(1, "   ", 3);
	putstr(msg);
	write(1, "\n", 1);
}




int print(t_data *st, t_philo *philo, char *msg)
{
	pthread_mutex_lock(&(st->flag_mutex));
	pthread_mutex_lock((st->death));
	if (st->die)
	{
		pthread_mutex_unlock(&(st->flag_mutex));
		pthread_mutex_unlock((st->death));
		return (1) ;
	}
	print_message(get_time() - st->time,philo->index, msg);
	// printf("%lld  %d   %s\n", get_time() - st->time,philo->index, msg);
	pthread_mutex_unlock((st->death));
	pthread_mutex_unlock(&(st->flag_mutex));
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*st;
	
	st = (t_data *)arg;
	pthread_mutex_lock(&(st->node_mutex));
	philo = get_node(st->s_philo, st);
	pthread_mutex_unlock(&(st->node_mutex));
	pthread_mutex_lock(&(st->var_mutex));
	while(!st->var)
		;
	pthread_mutex_unlock(&(st->var_mutex));
	// pthread_mutex_lock(&(philo->last_meal_mutex));
	// philo->last_meal = get_time();
	// pthread_mutex_unlock(&(philo->last_meal_mutex));
	if (philo->index % 2)
		usleep(1500);
	while (1)
	
	{



		pthread_mutex_lock(philo->l_fork);
	
		if (print(st, philo, FORK))
			return (NULL);
		pthread_mutex_lock(philo->r_fork);

		if (print(st, philo, FORK))
			return (NULL);



		if (print(st, philo, EAT))
			return (NULL);

		ft_usleep(st->time_2_eat);
		
		pthread_mutex_lock(&(philo->last_meal_mutex));
		philo->last_meal = get_time();
		pthread_mutex_unlock(&(philo->last_meal_mutex));

		
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		
		pthread_mutex_lock(&(philo->meals_n_mutex));
		philo->meals_n++; 
		pthread_mutex_unlock(&(philo->meals_n_mutex));
		if (print(st, philo, SLEEP))
			return (NULL);
		ft_usleep(st->time_2_sleep);
		if (print(st, philo, THINK))
			return (NULL);
	}
	return (NULL);
}

void	initializing_threads(t_data *st)
{
	t_mutex	*mutex;

	mutex = create_mutex(st->philo_n);
	st->mutexs = mutex;
	initialze_philo(st);
	create_threads(st);
}

int	check_meals(t_philo *philo, int n)
{
	while (philo)
	{
		if (philo->meals_n < n)
			return (1);
		philo = philo->next;			
	}
	return (0);
}
void	wait_death(t_data *st)
{
	t_philo	*philo;
	
	philo = st->s_philo;
	while (philo)
	{
		// if (st->eat_n != -1 && !check_meals(st->s_philo, st->eat_n))
		// {
		// 	pthread_mutex_lock((st->death));
		// 	return ;
		// }
		// puts("hello");
		pthread_mutex_lock(&(st->todie_mutex));
		pthread_mutex_lock(&(philo->last_meal_mutex));
		if (get_time() - philo->last_meal > (size_t)st->time_2_die)
		{
			pthread_mutex_lock((st->death));  //allocate on heap
			pthread_mutex_lock(&(st->time_mutex));
			pthread_mutex_lock(&(philo->index_mutex));
			printf("%lld  %d   died\n",get_time() - st->time, philo->index);
			pthread_mutex_unlock(&(st->todie_mutex));
			pthread_mutex_unlock(&(philo->last_meal_mutex));
			return ;
		}
		pthread_mutex_unlock(&(philo->last_meal_mutex));
		pthread_mutex_unlock(&(st->todie_mutex));
		if (!philo->next)
			philo = st->s_philo;
		else
			philo = philo->next;
	}
}
