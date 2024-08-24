/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/24 23:18:42 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <semaphore.h> 
# include <pthread.h> 
# include <signal.h>

typedef struct s_philo
{
	int								meals_n;
	int								index;
	int								pid;
	int								ppid;
	pthread_t						id;
	unsigned long long int			last_meal;
	sem_t							*last_meal_;
	sem_t							*meals_n_;
	struct s_philo					*next;	
}		t_philo;

typedef struct s_data
{
	size_t	time;
	sem_t	*die;
	sem_t	*die_2;
	int		index;
	int		philo_n;
	int		eat_n;
	int		time_2_die;
	int		time_2_eat;
	int		time_2_sleep;
	sem_t	*forks;
	sem_t	*start;
	t_philo	*s_philo;
}		t_data;

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

void	ft_free(t_data *st);
int		checker(int ac, char **av);
size_t	my_atoi(char *s);
size_t	get_time(void);
int		ft_usleep(useconds_t time);
void	how_to_use(void);
void	*routine(t_data *st, t_philo *philo);
int		initializing_philos(t_data *st);
void	initialze_philo(t_data *st);
int		create_philos(t_data *st);
void	wait_death(t_data *st, t_philo *philo);
sem_t	*create_semaphore(int i);
t_philo	*get_node(t_philo *philo, int index);
void	*true_routine(t_data *st, t_philo *philo);

#endif