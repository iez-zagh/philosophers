/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:18:15 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/20 09:31:23 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	how_to_use(void)
{
	write(1, "Usage: ./philo <num_philos> <time_die> ", 39);
	write(1, "<time_eat> <time_sleep> [num_eat]\n", 34);
	printf("\nArguments:\n");
	printf("  <num_philos> : Number of philosophers <= 200.\n");
	write(1, "  <time_die>   : Time in ms before a", 36);
	write(1, " philosopher dies. <= int_max\n", 30);
	write(1, "  <time_eat>   : Time in ms for a philosopher to", 48);
	write(1, " eat. <= int_max\n", 18);
	write(1, "  <time_sleep> : Time in ms for a philosopher to", 50);
	write(1, " sleep. <= int_max\n", 20);
	write(1, "  [num_eat]    : Optional. Times each philosopher", 51);
	write(1, " must eat before ending.\n", 26);
	printf("\nExample:\n");
	printf("  ./philo 5 800 200 100 7\n");
	write(1, "  Runs with 5 philosophers, 800ms to die,", 43);
	write(1, " 200ms to eat, 100ms to sleep, and each must eat", 48);
	write(1, " 7 times at least.\n", 20);
}

t_philo	*get_node(t_philo *philo, t_data *st)
{
	int			j;

	j = 0;
	pthread_mutex_lock(&(st->var_mutex));
	while (j < st->index)
	{
		philo = philo->next;
		j++;
	}
	st->index++;
	pthread_mutex_unlock(&(st->var_mutex));
	return (philo);
}
