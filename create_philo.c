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
	// pthread_mutex_lock(&philo->access);
	// pthread_mutex_unlock(&philo->access);
	printf("%d %s\n", philo->id, str);
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
		ft_printf("has taken left fork", ph->utils, ph);
		pthread_mutex_lock(ph->utils->fork + ph->right_fork);
		ft_printf("has taken right fork", ph->utils, ph);

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

int ft_num_eating_check(t_philo *philo, int n_eat,int nbr_of_philo, int argc)
{
	int i;
	i = 0;
	// (void) n_eat;
	if (argc != 6)
		return (0);
	if (i < nbr_of_philo)
	{
		if (philo[i].nbr_of_eat < n_eat)
			return (0);
	}
	return (1);
}
// grtTime() - first eat >= time to die
int check_is_died(t_utils *utils, t_philo *philo, int argc)
{

	int i;
	// t_philo **philo;
	// char *done_philos;

	// philo = (t_philo **)ph;
	// done_philos = malloc(data->nbr_of_philo);
	// memset((void*)done_philos, 0, data->nbr_of_philo);
	usleep(60000);
	while (utils->is_died == 0)
	{
		i = 0;
		while (i < utils->nbr_of_philo)
		{
			if (gettime() - philo[i].last_eat >= utils->time_to_die)
			{
				utils->is_died = 1;
				ft_printf("moooot",utils,philo);
				return (1);
			}
			if (ft_num_eating_check(philo, utils->nbr_of_times_each_philo_must_eat, utils->nbr_of_philo, argc))
			{

				// pthread_mutex_unlock(&data->death);
				utils->is_died = 1;
				usleep(100);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

void ft_create_threads(t_utils *utils, t_philo *philo)
{
	// t_philo *ph;
	// pthread_t check;
	int i;

	i = 0;
	// pthread_t	*thread = &(ph->thread); first time
	while (i < utils->nbr_of_philo)
	{
		philo[i].last_eat = gettime();
		// philo->last_eat = gettime();
		pthread_create(&(philo[i].thread), NULL, &routine, &(philo[i]));
		// pthread_create(&check, NULL ,check_is_died, &(philo[i]));
		i++;
	}
	// pthread_create(&check,NULL,check_is_died, &(ph[i]));
	// check_is_died(ph);
}

void ft_create_philo(t_utils *utils, t_philo **ph, int ac)
{
	int i;
	t_philo *philo;
	philo = *ph;
	i = 0;
	while (i < utils->nbr_of_philo)
	{
		philo[i].id = i + 1;
		// if (i == 0)
		// 	philo[i].left_fork = utils->nbr_of_philo - 1;
		// else
		// 	philo[i].left_fork = i - 1;
		philo[i].left_fork = i;
		
		philo[i].right_fork = (i + 1) % utils->nbr_of_philo;
		philo[i].utils = utils;
		philo[i].nbr_of_eat = 0;
		philo[i].last_eat = 0;
		philo[i].argc = ac;
		i++;
	}
	// printf("arg c : %d",philo[3].argc);
}
