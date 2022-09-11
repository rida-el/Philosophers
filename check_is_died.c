/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_died.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 15:04:28 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/10 22:47:15 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_num_eating_check(t_philo *philo, int n_eat, int nbr_of_philo, int argc)
{
	int	i;

	i = 0;
	if (argc != 6)
		return (0);
	if (i < nbr_of_philo)
	{
		if (philo[i].nbr_of_eat < n_eat)
			return (0);
	}
	return (1);
}

int	check_is_died(t_utils *utils, t_philo *philo, int argc)
{
	int	i;

	while (utils->is_died == 0)
	{
		i = -1;
		while (++i < utils->nbr_of_philo)
		{
			if (gettime() - philo[i].last_eat >= utils->time_to_die)
			{
				pthread_mutex_lock(&utils->print);
				printf("%lld %d died\n",
					((gettime() - utils->timestamp_in_ms)), philo->id);
				utils->is_died = 1;
				return (1);
			}
			if ((ft_num_eating_check(philo, utils->times_must_eat,
						utils->nbr_of_philo, argc)) == 1)
			{
				utils->is_died = 1;
				usleep(6000);
				return (1);
			}
		}
	}
	return (0);
}
