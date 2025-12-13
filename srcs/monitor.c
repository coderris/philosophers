/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 22:01:55 by lanton-m          #+#    #+#             */
/*   Updated: 2025/11/29 22:01:55 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*monitor_routine(void *arg)
{
	t_general_info *general;
	int 		i;
	long long 	no_eat_time;
	
	general = (t_general_info *)arg;
	while (1)
	{
		i = 0;
		while(i < general->philo_num)
		{
			pthread_mutex_lock(&general->state_lock);
			no_eat_time = ft_get_time() - general->philos[i].last_meal;
			if (no_eat_time > general->ttd)
			{
				general->stop = 1;
				pthread_mutex_unlock(&general->state_lock);
				pthread_mutex_lock(&general->print_lock);
				printf("%lld %d died\n", ft_current_time(general->start_time), general->philos[i].id);
				pthread_mutex_unlock(&general->print_lock);
				return (NULL);
			}
			pthread_mutex_unlock(&general->state_lock);
			i++;
		}
		i = 0;
		if (general->must_eat != -1)
		{
			pthread_mutex_lock(&general->state_lock);
			while (i < general->philo_num)
			{
				if (general->philos[i].meals_eaten < general->must_eat)
					break;
				i++;
			}
			pthread_mutex_unlock(&general->state_lock);
			if (i == general->philo_num)
			{
				pthread_mutex_lock(&general->state_lock);
				general->stop = 1;
				pthread_mutex_unlock(&general->state_lock);
				pthread_mutex_lock(&general->print_lock);
				printf("All philosophers have eaten the maximun number of meals\n");
				pthread_mutex_unlock(&general->print_lock);
				return (NULL);
			}
		}
		usleep(1000);
	}
}