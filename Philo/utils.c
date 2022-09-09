/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:09:18 by nnemeth           #+#    #+#             */
/*   Updated: 2022/09/09 17:27:45 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_set_now()
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	// t_msec = (t.tv_sec) * 1000 + (t.tv_usec) / 1000;
	return (((t.tv_sec) * 1000 + (t.tv_usec) / 1000));
}

int	ft_set_time(t_philo *a)
{
	struct timeval	t;
	// long int		t_msec;

	// t_msec = 0;
	gettimeofday(&t, NULL);
	a->now = (t.tv_sec) * 1000 + (t.tv_usec) / 1000;
	// printf("NOW -> %zu\n", a->start_time);
	return (a->now - a->start_time);
}
/*void	*dead_yet(void *data)
{
	long int now;
	int i;
	long int try;
	t_philo	*philo;
	t_table	*table;

	table = (t_table *)data;
	philo = table->philos;
	i = 0;
	now = ft_set_time();
	try = now - philo->last_meal;
	while (table->dead == 0)
	{
		if (i > table->n_philos)
			i = 0;
		if (try > philo->table->time_to_die)
		{
			philo->table->dead++;
			usleep(philo->table->time_to_die);
			if (philo->table->dead >= 1)
			{
				write_status("Is dead", philo);
			}
		}
		i++;
	}
	return (NULL);
}*/

void	*dead_yet(void *data)
{
	// long int now;
	int i;
	int meal;
	// long int try;
	t_philo	*philo;
	t_table	*table;

	philo = data;
	table = philo->table;
	// i = 0;
	// now = ft_set_time();
	// try = philo->start_time - philo->last_meal;
	// printf("die 2       %d\n", table->dead);
	while (table->dead != 1)
	{
		i = 0;
		meal = 0;
		while(i < table->n_philos)
		{
			if (table->philos[i].n_meals >= table->quant_food && table->quant_food != -1)
			{
				meal++;
				// printf("%d\n", meal);
				if (meal == table->n_philos)
					table->dead = 1;
			}
			// printf("%d ", ft_set_time(table->philos));
			// printf("%d ", table->philos[i].last_meal);
			// printf("%d ", table->time_to_die);
			// printf("%d\n", i);
			if (ft_set_time(table->philos) - table->philos[i].last_meal >= table->time_to_die)
			{
				// printf(" try = %ld\n", try);
				//printf("time %d\t philo %d, DEAD\n", ft_set_time(table->philos), table->philos->id);
				table->dead = 1;
				if (table->dead == 1)
				{
					write_status("Is dead", table->philos);
					break ;
				}
			}
			i++;
		}
	}
	return (NULL);
}

void	ft_usleep(long int time_ms, t_philo *a)
{
	long int	start;

	start = ft_set_time(a);
	while (1)
	{
		if (ft_set_time(a) - start >= time_ms)
			break ;
	}
}

int	ft_exit(void)
{
	return (1);
}


// long int time_check(void)
// {
// 	static long long	timer;

// 	if (timer == 0)
// 		timer = ft_set_time();
// 	return (ft_set_time() - timer);
// }
