/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/23 20:31:03 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	int						meals_n;
	int						index;
	int						pid;
	pthread_t				id;
	unsigned long long int	last_meal; 
	sem_t					*meals;
	struct s_philo			*next;	
}		t_philo;

typedef struct s_data
{
	size_t	time;
	sem_t	*die;
	int		die_;
	sem_t	*die_2;
	int		index;
	int		philo_n;
	int		eat_n;
	int		time_2_die;
	int		time_2_eat;
	int		time_2_sleep;
	sem_t	*forks;
	t_philo	*s_philo;
}		t_data;

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died"

void	ft_free(t_data *st, int flag);
int		checker(int ac, char **av);
size_t	my_atoi(char *s);
size_t	get_time(void);
int		ft_usleep(useconds_t time);
void	how_to_use(void);
void	*routine(t_data *st, t_philo *philo);
int		initializing_threads(t_data *st);
void	initialze_philo(t_data *st);
int		create_threads(t_data *st);
void	wait_death(t_data *st, t_philo *philo);
sem_t	*create_semaphore(int i);
t_philo	*get_node(t_philo *philo, t_data *st, int index);

#endif