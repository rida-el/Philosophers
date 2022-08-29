/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:36:14 by rel-maza          #+#    #+#             */
/*   Updated: 2022/08/29 16:01:21 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *philo)
{
	t_philo *ph;
	
	ph =(t_philo *) philo;
	while (ph->is_died == 0)
	{
		pthread_mutex_lock(&ph->utils->fork[ph->left_fork]);
		printf("timestamp_in_ms %d has taken a fork",(*ph).id);
		pthread_mutex_lock(&ph->utils->fork[ph->right_fork]);
		printf("timestamp_in_ms %d has taken a fork",(*ph).id);
		printf("timestamp_in_ms %d is eating",(*ph).id);
		usleep(ft_sleep(ph->utils->time_to_eat));
		ph->last_eat = gettime();
		ph->nbr_of_eat += 1;
		pthread_mutex_unlock(&ph->utils->fork[ph->left_fork]);
		pthread_mutex_unlock(&ph->utils->fork[ph->right_fork]);
		printf("timestamp_in_ms %d is sleeping",(*ph).id);
		usleep(ft_sleep(ph->utils->time_to_sleep));
		printf("timestamp_in_ms X is thinking");
	}
	
}

// grtTime() - first eat >= time to die
void	*check_is_died(t_philo **philo)
{
	int i;
	t_utils *data;
	
	data = (*philo)->utils;

	while (1)
	{
		i = 0;
		while (!(data->is_died))
		{
			if (gettime() - (*philo)->last_eat >= data->time_to_die)
			{
				pthread_mutex_lock(&data->print);
				printf("\033 %lld \033 %d \033 died\n",gettime(), i + 1);
				data->is_died = 1;
				return (1);	
			}
			if (ft_num_eating_check(philo, data->nbr_of_times_each_philo_must_eat  ,data->nbr_of_philo, (*philo)->argc) == 0)
			{
				usleep(100);
				data->is_died = 1;
				return (1);	
			}
		}
	}
}

int	ft_num_eating_check(t_philo *philo, int n_eat, int nbr_philo, int argc)
{
	int		i;

	i = 0;
	if (argc == 6)
	{
		if (philo[i].nbr_of_eat < n_eat)
			return (0);
		else
			return (1);
	}
	else
		return(0);
}



void	ft_create_threads(t_utils *utils,t_philo **philo)
{
	t_philo *ph;
	pthread_t check; 
	int i;

	i = 0;
	ph = *philo;
	// pthread_t	*thread = &(ph->thread);
	while (i < utils->nbr_of_philo)
	{
		pthread_create(&ph[i], NULL ,&routine, &ph[i]);	
		i++;
	}
	pthread_create(&check,NULL,&check_is_died, philo);
}



void	ft_create_philo(t_utils *utils,t_philo **philo, int ac)
{
	int i;
	
	i = 0;
	while (i < utils->nbr_of_philo)
	{
		(**philo).id = i + 1;
		if((**philo).id == 1)
			(**philo).right_fork = utils->nbr_of_philo;
		else
			(**philo).right_fork = i ;
		(**philo).left_fork = i + 1;
		(**philo).is_died = 0;
		(**philo).utils = utils;
		(**philo).nbr_of_eat = 0;
		i++;
	}
	(**philo).argc = ac;
	ft_create_threads(utils,philo);
	
}
