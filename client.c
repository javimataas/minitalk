/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:32:34 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/04 18:16:03 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send(int pid, char byte)
{
	int	bit_c;

	bit_c = 0;
	while (bit_c < 8)
	{
		if ((byte & (1 << bit_c)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		bit_c++;
	}
}

void	ft_check_sgn(int signal)
{
	(void)signal;
	ft_printf("MESSAGE SUCCESSFULLY RECEIVED! †\n");
}

int	main(int argc, char **argv)
{
	int					c;
	int					pid;
	struct sigaction	sign;

	if (argc == 3)
	{
		c = 0;
		pid = ft_atoi(argv[1]);
		sign.sa_handler = &ft_check_sgn;
		sigaction(SIGUSR1, &sign, NULL);
		while (argv[2][c] != '\0')
		{
			ft_send(pid, argv[2][c]);
			c++;
		}
		ft_send(pid, argv[2][c]);
	}
	else
		ft_printf("WRONG INPUT!!!\nTRY WITH THE FOLLOWING \
			INSTRUCTION:\t./client \"SERVER'S PID\" \"MESSAGE\"");
	return (0);
}
