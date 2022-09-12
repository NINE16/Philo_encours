/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:09:18 by nnemeth           #+#    #+#             */
/*   Updated: 2022/09/12 17:39:26 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_set_now(void)
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
	int		i;
	int		meal;
	t_philo	*philo;
	t_table	*table;

	philo = data;
	table = philo->table;
	while (table->dead != 1)
	{
		i = -1;
		meal = 0;
		while (++i < table->n_philos)
		{
			if (table->philos[i].n_meals >= table->quant_food
				&& table->quant_food != -1)
			{
				meal++;
				if (meal == table->n_philos)
					table->dead = 1;
			}
			if (ft_set_time(table->philos) - table->philos[i].last_meal
				>= table->time_to_die)
			{
				table->dead = 1;
				if (table->dead == 1)
				{
					write_status(GREY "Is dead", table->philos);
					break ;
				}
			}
		}
	}
	return (NULL);
}

void	ft_usleep(long int time_ms, t_philo *a, t_table *table)
{
	long int	start;

	start = ft_set_time(a);
	while (table->dead == 0)
	{
		if (ft_set_time(a) - start >= time_ms)
			break ;
		usleep(50);
	}
}

int	ft_exit(void)
{
	return (1);
}
