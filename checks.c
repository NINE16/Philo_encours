/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 15:45:27 by nemethnikol       #+#    #+#             */
/*   Updated: 2022/09/09 15:04:44 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int	ft_atoi_check(char *str)
{
	int		i;
	long	value;

	value = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			error();
	}
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			error();
		value *= 10;
		value += str[i] - '0';
		if (value >= MAX_INT)
			error();
		i++;
	}
	return (value);
}

void	error(void)
{
	write(2, "Error\n", 7);
	exit (0);
}
