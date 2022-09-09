
#include "philo.h"

int ft_num_eating_check(t_philo *philo, int n_eat, int nbr_of_philo, int argc)
{
    int i;
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

int check_is_died(t_utils *utils, t_philo *philo, int argc)
{

    int i;

    while (utils->is_died == 0)
    {
        i = 0;
        while (i < utils->nbr_of_philo)
        {
            if (gettime() - philo[i].last_eat >= utils->time_to_die)
            {
                utils->is_died = 1;
                pthread_mutex_lock(&utils->print);
                printf("%lld %d died\n", ((gettime() - utils->timestamp_in_ms)), philo->id);
                return (1);
            }
            if (ft_num_eating_check(philo, utils->nbr_of_times_each_philo_must_eat, utils->nbr_of_philo, argc))
            {
                utils->is_died = 1;
                usleep(100);
                return (1);
            }
            i++;
        }
    }
    return (0);
}