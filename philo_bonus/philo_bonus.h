/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/21 20:56:30 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
#include <semaphore.h> 

typedef struct s_sem
{
	sem_t			*sem;
	struct s_sem	*next;
}		t_sem;

typedef struct s_philo
{
	int						meals_n;
	int						index;
	unsigned long long int	last_meal;
	struct s_philo			*next;	
}		t_philo;

typedef struct s_data
{
	size_t					time;
	int						die;
	int						index;
	int						philo_n;
	int						eat_n;
	int						time_2_die;
	int						time_2_eat;
	int						time_2_sleep;
	t_sem					*sem;
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
int		create_threads(t_data *st);
void	wait_death(t_data *st);
t_sem	*create_semaphore(int i);
t_philo	*get_node(t_philo *philo, t_data *st);

#endif