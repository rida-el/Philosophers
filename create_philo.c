/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:36:14 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/01 23:33:57 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_printf(char *str, t_utils *utils, t_philo *philo)
{
	pthread_mutex_lock(&utils->print);
	printf("%lld %d %s\n",((gettime() - utils->timestamp_in_ms)), philo->id, str);
	pthread_mutex_unlock(&utils->print);
}

void *routine(void *philo)
{
	t_philo *ph;

	ph = (t_philo *)philo;
	if (ph->id % 2)
		usleep(ph->utils->time_to_eat * 1000 + 100);
	while (ph->utils->is_died == 0)
	{
		pthread_mutex_lock(ph->utils->fork + ph->left_fork);
		ft_printf("has taken a fork", ph->utils, ph);
		pthread_mutex_lock(ph->utils->fork + ph->right_fork);
		ft_printf("has taken a fork", ph->utils, ph);
		ft_printf("is eating", ph->utils, ph);
		ph->nbr_of_eat += 1;
		usleep(ph->utils->time_to_eat * 1000);
		ph->last_eat = gettime();
		pthread_mutex_unlock(ph->utils->fork + ph->left_fork);
		pthread_mutex_unlock(ph->utils->fork + ph->right_fork);
		ft_printf("is sleeping", ph->utils, ph);
		usleep(ph->utils->time_to_sleep * 1000);
		ft_printf("is thinking", ph->utils, ph);
	}
	return (NULL);
}



void ft_create_threads(t_utils *utils, t_philo *philo)
{
	int i;

	i = 0;
	utils->timestamp_in_ms = gettime();
	while (i < utils->nbr_of_philo)
	{
		philo[i].last_eat = gettime();
		pthread_create(&(philo[i].thread), NULL, &routine, &(philo[i]));
		i++;
	}

}

