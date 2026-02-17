/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 00:48:07 by lanton-m          #+#    #+#             */
/*   Updated: 2025/10/04 00:48:07 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_structs_init(t_general_info *general, long long *imputs)
{
	t_philo		*philo_array;
	int			i;

	general->philo_num = (int)imputs[0];
	general->ttd = imputs[1];
	general->tte = imputs[2];
	general->tts = imputs[3];
	general->must_eat = -1;
	if (imputs[4])
		general->must_eat = (int)imputs[4];
	ft_forks_init(general, imputs);
	philo_array = malloc(sizeof(t_philo) * general->philo_num);
	if (!philo_array)
		ft_malloc_err(&general, imputs);
	i = -1;
	while (++i < general->philo_num)
		ft_philos_init(&philo_array[i], general, i);
	general->philos = philo_array;
	general->start_time = 0;
	pthread_mutex_init(&general->print_lock, NULL);
	pthread_mutex_init(&general->state_lock, NULL);
	general->stop = 0;
	general->satisfied = 0;
}

void	ft_forks_init(t_general_info *general, long long *imputs)
{
	int	i;

	general->forks = malloc(sizeof(pthread_mutex_t) * general->philo_num);
	if (!general->forks)
	{
		printf("Malloc error\n");
		free(imputs);
		exit(1);
	}
	i = 0;
	while (i < general->philo_num)
	{
		pthread_mutex_init(&general->forks[i], NULL);
		i++;
	}
}

void	ft_philos_init(t_philo *philo, t_general_info *general, int idx)
{
	philo->id = idx + 1;
	philo->left_fork = idx;
	philo->right_fork = (idx + 1) % general->philo_num;
	philo->meals_eaten = 0;
	philo->last_meal = 0;
	philo->general = general;
}

void	ft_philo_threads_init(t_general_info *general)
{
	int	i;

	i = 0;
	while (i < general->philo_num)
	{
		pthread_create(&general->philos[i].thread, NULL,
			philosopher_routine, &general->philos[i]);
		i++;
	}
}

void	ft_print_status(t_philo *philo, char *str)
{
	long long	timestamp;

	pthread_mutex_lock(&philo->general->state_lock);
	if (!philo->general->stop)
	{
		pthread_mutex_lock(&philo->general->print_lock);
		timestamp = ft_current_time(philo->general->start_time);
		printf("%lld %d %s\n", timestamp, philo->id, str);
		pthread_mutex_unlock(&philo->general->print_lock);
	}
	pthread_mutex_unlock(&philo->general->state_lock);
}
