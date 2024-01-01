/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:10:05 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/01 22:03:27 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	_nsx_handler(int sig, struct __siginfo *s_info, void *_custom_data)
{
	static char	bits;
	static int	len;

	(void)_custom_data;
	if (sig == SIGUSR1)
		bits = (bits << 1) + 1;
	else if (sig == SIGUSR2)
		bits = (bits << 1);
	len++;
	if (len == 8)
	{
		if (bits == '\0')
		{
			kill(s_info->si_pid, SIGUSR1);
			write(1, "\n", 1);
		}
		else
			write(1, &bits, 1);
		bits = 0;
		len = 0;
	}
}

void	_nsx_putbanner(int pid)
{
	_nsx_ps("\033[1J\033[1;1H");
	_nsx_ps("\n");
	_nsx_pcolor('b');
	_nsx_ps("███╗░░░███╗██╗███╗░░██╗██╗ ████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
	_nsx_ps("████╗░████║██║████╗░██║██║ ╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
	_nsx_ps("██╔████╔██║██║██╔██╗██║██║ ░░░██║░░░███████║██║░░░░░█████═╝░\n");
	_nsx_ps("██║╚██╔╝██║██║██║╚████║██║ ░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
	_nsx_ps("██║░╚═╝░██║██║██║░╚███║██║ ░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
	_nsx_ps("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝ ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");
	_nsx_ps("bonus					\033[1;34m@mait-elk\n");
	_nsx_p("\n\nPID:	\033[1;33m[ %d ]\n", pid);
	_nsx_ps("\033[1;34m");
	_nsx_ps("____________________________________________________________\n");
	_nsx_ps("\033[0m\n");
}

int	main(void)
{
	struct sigaction	act;
	int					pid;

	pid = getpid();
	act.__sigaction_u.__sa_sigaction = _nsx_handler;
	_nsx_putbanner(pid);
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
	{
		pause();
	}
	return (0);
}