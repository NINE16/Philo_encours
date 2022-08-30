/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nemethnikol <nemethnikol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:20:14 by nemethnikol       #+#    #+#             */
/*   Updated: 2022/08/22 12:19:32 by nemethnikol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

t_philo	create_philos(t_table *tab)
{
	t_philo	*philo;
	int		i;

	philos = malloc(tab->n_philos * sizeof(t_philo));
	i = -1;
	while (++i < tab->n_philos)
	(
		philo[i]->id = i + 1;
		
		philo[i]->meals = 0;
		philo[i]->last_meal = 0;
		philo[i]->wait = 0;
		pthread_mutex_init(philo[i]->fork, NULL);
		printf("%d %d is thinking\n", 0, philos[i].id);

	)
	return (philos);
}

int	get_args(int argc, char **argv, t_table *table)
{
	table->n_philos = ft_atoi_check(argv[1]);
	table->time_to_die = ft_atoi_check(argv[2]);
	table->time_to_eat = ft_atoi_check(argv[3]);
	table->time_to_sleep = ft_atoi_check(argv[4]);
	if (argc == 6)
		table->quant_food = ft_atoi_check(argv[5]);
}

int	main(int argc, char **argv)
{
	// t_philo	*philo;
	t_table	*table;

	philo = NULL;
	if (argc == 5 || argc == 6)
	{
		get_args(argc, argv, philo);
	}
	table->death = 0;
	table->philos = create_philos(table);
	philosophate(table);
}