/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/19 13:05:09 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <pthread.h>
# include <time.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_mutex
{
	pthread_mutex_t	mutex;
	struct s_mutex	*next;
}		t_mutex;

typedef struct s_philo
{
	pthread_t				id;
	int						meals_n;
	int						index;
	unsigned long long int	last_meal;
	pthread_mutex_t			last_meal_mutex;
	pthread_mutex_t			meals_n_mutex;
	pthread_mutex_t			*l_fork;
	pthread_mutex_t			*r_fork;
	struct s_philo			*next;	
}		t_philo;

typedef struct s_data
{
	pthread_mutex_t			node_mutex;
	size_t					time;
	int						die;
	int						index;
	int						f;
	int						philo_n;
	int						eat_n;
	pthread_mutex_t			death;	
	pthread_mutex_t			var_mutex;
	pthread_mutex_t			f_mutex;
	int						time_2_die;
	int						time_2_eat;
	int						time_2_sleep;
	t_mutex					*mutexs;
	t_philo					*s_philo;
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
void	*routine(void *st);
int		initializing_threads(t_data *st);
void	initialze_philo(t_data *st);
void	create_threads(t_data *st);
void	wait_death(t_data *st);
t_mutex	*create_mutex(int i);
t_philo	*get_node(t_philo *philo, t_data *st);

#endif