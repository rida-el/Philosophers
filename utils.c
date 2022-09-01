/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-maza <rel-maza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:08:41 by rel-maza          #+#    #+#             */
/*   Updated: 2022/09/01 23:05:07 by rel-maza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int ft_atoi(const char *str)
{
	int i;
	int sign;
	int ret;

	ret = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		ret = ret * 10 + (str[i] - 48);
		i++;
	}
	return (sign * ret);
}

long long ft_sleep(int time_in_milliseconds)
{
	long long time_in_micro;
	time_in_micro = time_in_milliseconds * 1000;
	return (time_in_micro);
}
// tv_sec used for seconds
// tv_usec used for microseconds
long long gettime()
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_usec * 1000 + current_time.tv_sec / 1000);
}