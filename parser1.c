/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/10 10:14:29 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	my_atoi(char *s)
{
	size_t	nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		nbr = nbr * 10 + s[i] - '0';
		if (nbr > INT_MAX)
			return (-1);
		i++;
	}
	return (nbr);
}

int	checker(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '+' && av[i][j + 1])
			j++;
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

void how_to_use(void)
{
	printf("Usage: ./philo <num_philos> <time_die> <time_eat> <time_sleep> [num_eat]\n");
	printf("\nArguments:\n");
	printf("  <num_philos> : Number of philosophers <= 200.\n");
	printf("  <time_die>   : Time in ms before a philosopher dies. <= int_max\n");
	printf("  <time_eat>   : Time in ms for a philosopher to eat. <= int_max\n");
	printf("  <time_sleep> : Time in ms for a philosopher to sleep. <= int_max\n");
	printf("  [num_eat]    : Optional. Times each philosopher must eat before ending.\n");
	printf("\nExample:\n");
	printf("  ./philo 5 800 200 100 7\n");
	printf("  Runs with 5 philosophers, 800ms to die, 200ms to eat, 100ms to sleep, and each must eat 7 times at least.\n");
}
