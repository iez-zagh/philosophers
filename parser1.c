/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/04 23:12:53 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	parser(int ac, char **av)
{
	t_data	*st;

	st = malloc (sizeof(t_data));
	if (!st)
		error(st, 1);
	if (checker(ac, av) == 1)
		error(st, 2);
	st->philo_n = my_atoi(av[1]);
	st->time_2_die = my_atoi(av[2]);
	st->time_2_eat = my_atoi(av[3]);
	st->time_2_sleep = my_atoi(av[4]);
	if (ac == 6)
		st->eat_n = my_atoi(av[5]);
	// if (st->philo_n > 200 || st->time_2_die > 1000000
	// 	|| st->time_2_eat > 1000000 || st->time_2_sleep > 1000000)
	threads1(st);
}

size_t	my_atoi(char *s)
{
	size_t	nbr = 0;
	int		i = 0;

	i = 0;

	while (s[i])
	{
		nbr = nbr * 10 + s[i] - '0';
		i++;
	}
	return nbr;
}

int	checker(int ac, char **av)
{
	int	i;
	int	j;
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
