/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/03 07:33:43 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <libc.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

// #define malloc(x) NULL;

typedef struct s_data
{
	int	philo_n;
	int	eat_n;
	int	time_2_die;
	int	time_2_eat;
	int	time_2_sleep;
	int	*forks;
}				t_data;

void		parser(int ac, char **av);
int			checker(int ac, char **av);
void		error(t_data *st, int y);
size_t		my_atoi(t_data *st, char *s);
void		*philo_life(t_data *st);
void		threads1(t_data *st);
void		initalize_threads(t_data *st);

#endif