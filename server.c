/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmatas-p <jmatas-p@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:19:11 by jmatas-p          #+#    #+#             */
/*   Updated: 2023/04/04 18:43:27 by jmatas-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_display(int signal, siginfo_t *info, void *uap)
{
	static unsigned char	byte;
	static int				bit_c;

	(void)uap;
	if (signal == SIGUSR1)
		byte = byte | (1 << bit_c);
	bit_c++;
	if (bit_c == 8)
	{
		if (byte == '\0')
		{
			ft_printf("\n");
			kill(info->si_pid, SIGUSR1);
		}
		else
			ft_printf("%c", byte);
		byte = 0;
		bit_c = 0;
	}
}

void	ft_set_banner(int pid)
{
	ft_printf("%s\t                 _/~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\_\n",
		RED);
	ft_printf("\t                /~              ·.              ~\\\n");
	ft_printf("\t              .~                 %s†%s                ~.\n",
		YELLOW, RED);
	ft_printf("\t          ()\\/______                          ______\\/()\n");
	ft_printf("\t         .-''      ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~     ``-.\n");
	ft_printf("\t      .-~              ____________________              ~-.\n");
	ft_printf("\t      `~~/~~~~~~~~~~~~TTTTTTTTTTTTTTTTTTTTTT~~~~~~~~~~~~\\~~'\n");
	ft_printf("\t      | | | #### #### || || | | [] | | || || #### #### | | |\n");
	ft_printf("\t      ;__\\|____________|++++++++++++++++++|____________|/__;\n");
	ft_printf("\t       (~~====_____________________________________====~~~)\n");
	ft_printf("\t        \\------____________[%s MA %d %s]__________-------/\n",
		END, pid, RED);
	ft_printf("\t           ||      ||       ~~~~~~~~~~       ||      ||\n");
	ft_printf("\t            \\______/                          \\______/%s\n",
		END);
}

int	main(void)
{
	struct sigaction	sgn;

	sgn.sa_sigaction = &ft_display;
	sgn.sa_flags = SA_SIGINFO;
	sigemptyset(&sgn.sa_mask);
	sigaddset(&sgn.sa_mask, SIGUSR1);
	sigaddset(&sgn.sa_mask, SIGUSR2);
	ft_set_banner(getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sgn, NULL);
		sigaction(SIGUSR2, &sgn, NULL);
		pause();
	}
	return (0);
}
