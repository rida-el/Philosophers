/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:36:14 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/01 16:58:43 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_printf(char *str, t_utils *utils, int id) 
{
	pthread_mutex_lock(&utils->print);
	printf("%d %s\n", id, str);
	pthread_mutex_unlock(&utils->print);
}



void	*routine(void *philo)
{
	t_philo *ph;
	
	ph =(t_philo *)philo;
	while (ph->utils->is_died == 0)
	{
		pthread_mutex_lock(&(ph->utils->fork[ph->left_fork]));
		
		// pthread_mutex_lock(&(ph->utils->print));
		// printf("%d has taken a fork\n",(*ph).id);
		// pthread_mutex_unlock(&(ph->utils->print));
		ft_printf("has taken left fork",ph->utils,ph->id);
		
		pthread_mutex_lock(&(ph->utils->fork[ph->right_fork]));
		
		// pthread_mutex_lock(&(ph->utils->print));
		// printf("%d has taken a fork\n",(*ph).id);
		// pthread_mutex_unlock(&(ph->utils->print));
		ft_printf("has taken right fork",ph->utils,ph->id);
		
		// pthread_mutex_lock(&(ph->utils->print));
		// printf("%d is eating\n",(*ph).id);
		// pthread_mutex_unlock(&(ph->utils->print));
		ft_printf("is eating",ph->utils,ph->id);
		
		usleep(ph->utils->time_to_eat * 1000);
		ph->last_eat = gettime();
		ph->nbr_of_eat += 1;
		pthread_mutex_unlock(&(ph->utils->fork[ph->left_fork]));
		// ft_printf("put down left fork",ph->utils,ph->id);
		pthread_mutex_unlock(&(ph->utils->fork[ph->right_fork]));
		// ft_printf("put down right fork",ph->utils,ph->id);
		
		// pthread_mutex_lock(&(ph->utils->print));
		// printf("%d is sleeping\n",(*ph).id);
		// pthread_mutex_unlock(&(ph->utils->print));
		ft_printf("is sleeping",ph->utils,ph->id);
		
		usleep(ph->utils->time_to_sleep * 1000);
		
		// pthread_mutex_lock(&(ph->utils->print));
		// printf("%d is thinking\n",(*ph).id);
		// pthread_mutex_unlock(&(ph->utils->print));
		ft_printf("is thinking",ph->utils,ph->id);
	}
	return(NULL);
}

// grtTime() - first eat >= time to die
void	*check_is_died(void *ph)
{
	
	int i;
	t_utils *data;
	t_philo	**philo;

	philo = (t_philo **)ph;
	
	data = (*philo)->utils;

	while (1)
	{
		i = 0;
		while (i < data->nbr_of_philo)
		{
			if (gettime() - (philo[i])->last_eat > data->time_to_die)
			{
				ft_printf("has died", data, i + 1);
				data->is_died = 1;
				break ;
			}
			if (ft_num_eating_check(philo[i], data->nbr_of_times_each_philo_must_eat , (*philo)->argc) == 0)
			{
				data->is_died = 1;
				break;
				
			}
			i++;
		}
		usleep(50);
		if (data->is_died) {
			return NULL ;
		}
	}
}

int	ft_num_eating_check(t_philo *philo, int n_eat, int argc)
{
	int		i;

	i = 0;
	if (argc == 6)
	{
		if (philo[i].nbr_of_eat < n_eat)
			return (0);
		return (1);
	}
	return(1);
}

void	ft_create_threads(t_utils *utils,t_philo *philo)
{
	// t_philo *ph;
	// pthread_t check; 
	int i;

	i = 0;
	// pthread_t	*thread = &(ph->thread); first time
	while (i < utils->nbr_of_philo)
	{
		// philo[i].last_eat = gettime();
		if (philo->id % 2)
			usleep(utils->time_to_eat * 1000 + 50);
		philo->last_eat = gettime();
		pthread_create(&(philo[i].thread), NULL ,&routine, &(philo[i]));
		// pthread_create(&check, NULL ,check_is_died, &(philo[i]));
		i++;
	}
	// pthread_create(&check,NULL,check_is_died, &(ph[i]));
	// check_is_died(ph);
	
}



void	ft_create_philo(t_utils *utils,t_philo *philo, int ac)
{
	int i;
	
	i = 0;
	while (i < utils->nbr_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].argc = ac;
		if(i == 0)
			philo[i].right_fork = utils->nbr_of_philo;
		else
			philo[i].right_fork = i ;
		philo[i].left_fork = i + 1;
		philo[i].utils = utils;
		philo[i].nbr_of_eat = 0;
		philo[i].last_eat = 0;
		i++;
		//  printf("philo num : %d left fork : %d right fork : %d and time to eat : %d\n",(*philo)[i].id,(*philo)[i].left_fork,(*philo)[i].right_fork, (*philo)[i].utils.time_to_die);
	}
	
	
	// printf("arg c : %d", (*philo)->argc);
}
