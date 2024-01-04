/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:10:05 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/03 14:00:23 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	_nsx_handler(int sig, siginfo_t *s_info, void *_custom_data)
{
	static t_nsx_byte	byte;
	static int			pid;

	(void)_custom_data;
	if (pid == 0)
		pid = s_info->si_pid;
	if (pid != s_info->si_pid)
	{
		byte.bits = 0;
		byte.len = 0;
		pid = 0;
		_nsx_pc('\n');
	}
	if (((sig == SIGUSR1) || (sig == SIGUSR2)) && byte.len++)
		byte.bits = (byte.bits << 1) + (sig == SIGUSR1);
	if (byte.len == 8)
	{
		if (byte.bits == '\0')
			write(1, "\n", 1);
		else
			write(1, &byte.bits, 1);
		byte.bits = 0;
		byte.len = 0;
		pid = 0;
	}
}

void	_nsx_putbanner(int pid)
{
	_nsx_ps("\033[1J\033[1;1H");
	_nsx_pcolor('b');
	_nsx_ps("\n");
	_nsx_ps("███╗░░░███╗██╗███╗░░██╗██╗ ████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
	_nsx_ps("████╗░████║██║████╗░██║██║ ╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
	_nsx_ps("██╔████╔██║██║██╔██╗██║██║ ░░░██║░░░███████║██║░░░░░█████═╝░\n");
	_nsx_ps("██║╚██╔╝██║██║██║╚████║██║ ░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
	_nsx_ps("██║░╚═╝░██║██║██║░╚███║██║ ░░░██║░░░██║░░██║███████╗██║░╚██╗\n");
	_nsx_ps("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝ ░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");
	_nsx_ps("MANDATORY					\033[1;34m@mait-elk\n");
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
	while (1)
	{
		sigaction(SIGUSR1, &act, 0);
		sigaction(SIGUSR2, &act, 0);
		pause();
	}
	return (0);
}
