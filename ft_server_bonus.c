/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:10:05 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/09 13:39:54 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	_nsx_handler(int sig, struct __siginfo *s_info, void *_custom_data)
{
	static int			pid;
	static t_nsx_byte	byte;

	(void)_custom_data;
	if (pid == 0)
		pid = s_info->si_pid;
	if (pid != s_info->si_pid)
	{
		pid = 0;
		byte.bits = 0;
		byte.len = 0;
		write(1, "\n", 1);
	}
	if (sig == SIGUSR1 || sig == SIGUSR2)
		byte.bits = (byte.bits << 1) + (sig == SIGUSR1);
	byte.len++;
	if (byte.len == 8)
	{
		if (byte.bits == '\0')
			kill(s_info->si_pid, SIGUSR1);
		else
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
	act.sa_mask = 0;
	act.sa_flags = 0;
	_nsx_putbanner(pid, "BONUS PART");
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
