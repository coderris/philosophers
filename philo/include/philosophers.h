/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 00:22:54 by lanton-m          #+#    #+#             */
/*   Updated: 2026/02/18 00:22:54 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo	t_philo;

typedef struct s_general_info
{
	int				philo_num;
	long long		ttd;
	long long		tte;
	long long		tts;
	int				must_eat;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	state_lock;
	int				stop;
	int				satisfied;
	t_philo			*philos;
}	t_general_info;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	long long		last_meal;
	pthread_t		thread;
	t_general_info	*general;
}	t_philo;

// parser.c

int			parser(int argc, char **argv);
long long	*ft_handle_input(char **argv);

// time.c

long long	ft_get_time(void);
long long	ft_current_time(long long start_time);

// utils.c

void		ft_structs_init(t_general_info *general, long long *imputs);
void		ft_forks_init(t_general_info *general, long long *imputs);
void		ft_philos_init(t_philo *philo, t_general_info *general, int idx);
void		ft_philo_threads_init(t_general_info *general);
void		ft_print_status(t_philo *philo, char *str);

// rutine.c

void		*philosopher_routine(void *arg);
int			stop_check(t_philo *philo);

// rutine_utils.c

void		sleep_start(t_philo *philo);
char		*one_philo_case(t_philo *philo);
int			check_sleep(t_philo *philo, long long check_time, long long start);

// monitor.c

void		*monitor_routine(void *arg);

// cleaners.c

void		clean_all(t_general_info *general, long long *imputs);
void		ft_malloc_err(t_general_info **general, long long *imputs);
#endif
