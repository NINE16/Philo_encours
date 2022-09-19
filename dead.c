/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:10:59 by nnemeth           #+#    #+#             */
/*   Updated: 2022/09/19 18:25:51 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		checker(table, meal, i);
	}
	return (NULL);
}

void	checker(t_table *table, int meal, int i)
{
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
