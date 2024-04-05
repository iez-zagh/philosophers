/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/04 23:08:54 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <libc.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

// #define malloc(x) NULL;

typedef struct s_philo
{
	int	died;
	int	ate;
	int	sleep;
}				s_philo;


typedef struct s_data
{
	int		philo_n;
	int		eat_n;
	int		time_2_die;
	int		time_2_eat;
	int		time_2_sleep;
	int		*forks;
	s_philo	*s_philo;
}			t_data;

# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define FORK "has taken a fork"
# define DIED "died ☠️"

void		parser(int ac, char **av);
int			checker(int ac, char **av);
void		error(t_data *st, int y);
size_t		my_atoi(char *s);
void		*philo_life(void *arg);
void		threads1(t_data *st);
size_t		get_time(t_data *st);
int			ft_usleep(useconds_t time, t_data *st);

#endif