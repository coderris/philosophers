/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 23:39:12 by lanton-m          #+#    #+#             */
/*   Updated: 2025/10/03 23:39:12 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

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
	t_philo			*philos;
	int				stop;
	int				satisfied;
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

int				parser(int argc, char **argv);
long long		*ft_handle_input(int rules, char **argv);
void			ft_structs_init(t_general_info *general, long long *imputs);
void			ft_philos_init(t_philo *philo, t_general_info *general, int idx);
void			ft_forks_init(t_general_info *general, long long *imputs);
long long		ft_get_time(void);
#endif
