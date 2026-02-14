/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 19:27:57 by lanton-m          #+#    #+#             */
/*   Updated: 2026/02/14 19:39:16 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	stop_check(t_philo *philo)
{
	int	stop_value;

	pthread_mutex_lock(&philo->general->state_lock);
	stop_value = philo->general->stop;
	pthread_mutex_unlock(&philo->general->state_lock);
	return (stop_value);
}

void	sleep_start(t_philo *philo)
{
	long long	start_time_local;

	pthread_mutex_lock(&philo->general->state_lock);
	start_time_local = philo->general->start_time;
	pthread_mutex_unlock(&philo->general->state_lock);
	while (start_time_local == 0)
	{
		usleep(10);
		pthread_mutex_lock(&philo->general->state_lock);
		start_time_local = philo->general->start_time;
		pthread_mutex_unlock(&philo->general->state_lock);
	}
}

char	*one_philo_case(t_philo *philo)
{
	ft_print_status(philo, "has taken a fork");
	usleep(philo->general->ttd * 1000);
	return (NULL);
}
