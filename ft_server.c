/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:10:05 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/09 13:39:35 by mait-elk         ###   ########.fr       */
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
	if (((sig == SIGUSR1) || (sig == SIGUSR2)))
		byte.bits = (byte.bits << 1) + (sig == SIGUSR1);
	byte.len++;
	if (byte.len == 8)
	{
		write(1, &byte.bits, 1);
		byte.bits = 0;
		byte.len = 0;
	}
}

int	main(void)
{
	struct sigaction	act;
	int					pid;

	pid = getpid();
	act.__sigaction_u.__sa_sigaction = _nsx_handler;
	act.sa_flags = 0;
	act.sa_mask = 0;
	_nsx_putbanner(pid, "MONDATORY PART");
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}
