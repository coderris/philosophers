/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 21:51:19 by lanton-m          #+#    #+#             */
/*   Updated: 2025/11/29 21:51:19 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	ft_take_forks(t_philo *philo)
{
	int	first;
	int	second;

	first = philo->left_fork;
	second = philo->right_fork;
	if (philo->left_fork > philo->right_fork)
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	pthread_mutex_lock(&philo->general->forks[first]);
	ft_print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->general->forks[second]);
	ft_print_status(philo, "has taken a fork");
}

static void	ft_eat(t_philo *philo)
{
	long long start;

	pthread_mutex_lock(&philo->general->state_lock);
	philo->meals_eaten++;
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->general->state_lock);
	ft_print_status(philo, "is eating");
	start = ft_get_time();
	while (ft_get_time() - start < philo->general->tte)
	{
		if (stop_check(philo))
			return;
		usleep(1000);
	}
}

static void ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->general->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->general->forks[philo->right_fork]);
}

static void	ft_sleep_and_think(t_philo *philo)
{
	ft_print_status(philo, "is sleeping");
	usleep(philo->general->tts * 1000);
	ft_print_status(philo, "is thinking");
}

void	*philosopher_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;

	if (philo->general->philo_num == 1)
	{
		ft_print_status(philo, "has taken a fork");
		usleep(philo->general->ttd * 1000);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(1000);
	while(1)
	{
		if (stop_check(philo))
			break;
		ft_take_forks(philo);
		if (stop_check(philo))
		{
			ft_drop_forks(philo);
			break;
		}
		ft_eat(philo);
		ft_drop_forks(philo);
		if (stop_check(philo))
			break;
		ft_sleep_and_think(philo);
	}
	return (NULL);
}

int stop_check(t_philo *philo)
{
	int	stop_value;

	pthread_mutex_lock(&philo->general->state_lock);
	stop_value = philo->general->stop;
	pthread_mutex_unlock(&philo->general->state_lock);
	return (stop_value);
}