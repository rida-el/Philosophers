/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:36:14 by rel-maza          #+#    #+#             */
/*   Updated: 2022/08/28 18:31:40 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	routine()
{
	
}


void	ft_create_threads(t_utils *utils,t_philo **philo)
{
	t_philo *ph;
	int i;

	i = 0;
	ph = *philo;
	// pthread_t	*thread = &(ph->thread);
	while (i < utils->nbr_of_philo)
	{
		pthread_create(&ph[i], NULL ,&routine, NULL);	
		i++;
	}
	
}



void	ft_create_philo(t_utils *utils,t_philo **philo)
{
	int i;
	t_utils data;
	*utils = data;
	i = 0;
	while (i < data.nbr_of_philo)
	{
		(**philo).id = i + 1;
		if((**philo).id = 1)
			(**philo).right_fork = data.nbr_of_philo;
		else
			(**philo).right_fork = i ;
		(**philo).left_fork = i + 1;
		(**philo).is_died = 0;
		i++;
	}
	ft_create_threads(utils,philo);
	
}