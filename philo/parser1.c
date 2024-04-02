/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/04/02 22:07:03 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	paser(int ac, char **av)
{
	t_data	*st;

	if (checker(ac, av))
		error(st, 2);
	st = malloc (sizeof(t_data));
	if (!st)
		error(st, 1);
	st->philo_n = my_atoi(av[0]);
	// st->time_2_die = my_atoi(av[1]);
}

// unsigned long long	my_atoi(char *s)
// {

// }

int	checker(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
