/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 23:24:58 by rel-maza          #+#    #+#             */
/*   Updated: 2022/08/31 19:49:41 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_insert_args(t_utils *utils, int argc, char **argv)
{
	utils->nbr_of_philo = ft_atoi(argv[1]);
	utils->time_to_die = ft_atoi(argv[2]);
	utils->time_to_eat = ft_atoi(argv[3]);
	utils->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		utils->times_must_eat = ft_atoi(argv[5]);
	utils->is_died = 0;
	utils->timestamp_in_ms = 0;
}

void	ft_create_philo(t_utils *utils, t_philo **ph, int ac)
{
	int		i;
	t_philo	*philo;

	philo = *ph;
	i = 0;
	while (i < utils->nbr_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].left_fork = i;
		philo[i].right_fork = (i + 1) % utils->nbr_of_philo;
		philo[i].utils = utils;
		philo[i].nbr_of_eat = 0;
		philo[i].last_eat = 0;
		philo[i].argc = ac;
		i++;
	}
}
