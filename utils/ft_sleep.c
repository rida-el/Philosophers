/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 13:28:32 by rel-maza          #+#    #+#             */
/*   Updated: 2022/08/29 13:29:27 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_sleep(int time_in_milliseconds)
{
	long long	time_in_micro;
	time_in_micro = time_in_milliseconds * 1000;
	return(time_in_micro);
}