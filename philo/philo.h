/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/03 18:01:32 by iez-zagh         ###   ########.fr       */
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
}				t_data;


void		parser(int ac, char **av);
int			checker(int ac, char **av);
void		error(t_data *st, int y);
size_t		my_atoi(t_data *st, char *s);
void		*philo_life(void *arg);
void		threads1(t_data *st);

#endif