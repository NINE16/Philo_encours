/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:09:18 by nnemeth           #+#    #+#             */
/*   Updated: 2022/09/19 18:11:38 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_set_now(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (((t.tv_sec) * 1000 + (t.tv_usec) / 1000));
}

int	ft_set_time(t_philo *a)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	a->now = (t.tv_sec) * 1000 + (t.tv_usec) / 1000;
	return (a->now - a->start_time);
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

void	write_status(char *str, t_philo *philo)
{
	long int	time;

	time = ft_set_time(philo);
	pthread_mutex_lock(&philo->table->write);
	printf(WHITE "%s%ld ", "Time:", time);
	printf(WHITE "  Philo %d    %s\n", philo->id, str);
	pthread_mutex_unlock(&philo->table->write);
}
