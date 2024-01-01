/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 23:10:05 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/01 22:00:12 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	_nsx_handler(int sig)
{
	static char	bits;
	static int	len;

	if (sig == SIGUSR1)
		bits = (bits << 1) + 1;
	else if (sig == SIGUSR2)
		bits = (bits << 1);
	len++;
	if (len == 8)
	{
		if (bits == '\0')
			write(1, "\n", 1);
		else
			write(1, &bits, 1);
		bits = 0;
		len = 0;
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
	int	pid;

	pid = getpid();
	_nsx_putbanner(pid);
	signal(SIGUSR1, _nsx_handler);
	signal(SIGUSR2, _nsx_handler);
	while (1)
	{
		pause();
	}
	return (0);
}
