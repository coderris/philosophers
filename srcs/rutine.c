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

void	*philosopher_routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;

	while(!philo->general->stop)
	{
		ft_take_forks(philo);
		ft_eat(philo);
		ft_drop_forks(philo);
		ft_sleep_and_think(philo);
	}
	return (NULL);
}

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
	pthread_mutex_lock(&philo->general->state_lock);
	start_eating = ft_get_time();
	philo->meals_eaten++;
	philo->last_meal = ft_get_time();
	pthread_mutex_unlock(&philo->general->state_lock);
	ft_print_status(philo, "is eating")
	usleep(philo->general->tte * 1000);
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