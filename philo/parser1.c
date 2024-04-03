/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/03 17:53:58 by iez-zagh         ###   ########.fr       */
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
	st->philo_n = my_atoi(st, av[1]);
	st->time_2_die = my_atoi(st, av[2]);
	st->time_2_eat = my_atoi(st, av[3]);
	st->time_2_sleep = my_atoi(st, av[4]);
	if (ac == 6)
		st->eat_n = my_atoi(st, av[5]);
	threads1(st);
}

size_t	my_atoi(t_data *st, char *s)
{
	size_t	nbr = 0;
	int		i = 0;

	i = 0;
	while (s[i])
	{
		nbr = nbr * 10 + s[i] - '0';
		if (nbr > 1000000)
			error (st, 3);
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
