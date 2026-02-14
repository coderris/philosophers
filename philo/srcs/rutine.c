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
	if (philo->id % 2 == 1)
	{
		pthread_mutex_lock(&philo->general->forks[philo->left_fork]);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->general->forks[philo->right_fork]);
		ft_print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->general->forks[philo->right_fork]);
		ft_print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->general->forks[philo->left_fork]);
		ft_print_status(philo, "has taken a fork");
	}
}

static void	ft_eat(t_philo *philo)
{
	long long	start;

	pthread_mutex_lock(&philo->general->state_lock);
	philo->meals_eaten++;
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->general->state_lock);
	ft_print_status(philo, "is eating");
	start = ft_get_time();
	while (ft_get_time() - start < philo->general->tte)
	{
		if (stop_check(philo))
			return ;
		usleep(1000);
	}
}

static void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->general->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->general->forks[philo->right_fork]);
}

static void	ft_sleep_and_think(t_philo *philo)
{
	long long	think_time;

	ft_print_status(philo, "is sleeping");
	usleep(philo->general->tts * 1000);
	ft_print_status(philo, "is thinking");
	think_time = (philo->general->ttd - philo->general->tte
			- philo->general->tts) / 2;
	if (think_time > 0)
		usleep(think_time * 1000);
	else if (philo->general->philo_num % 2 == 1)
		usleep(1000);
}

void	*philosopher_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	sleep_start(philo);
	if (philo->general->philo_num == 1)
		return (one_philo_case(philo));
	while (1)
	{
		if (stop_check(philo))
			break ;
		ft_take_forks(philo);
		if (stop_check(philo))
		{
			ft_drop_forks(philo);
			break ;
		}
		ft_eat(philo);
		ft_drop_forks(philo);
		if (stop_check(philo))
			break ;
		ft_sleep_and_think(philo);
	}
	return (NULL);
}
