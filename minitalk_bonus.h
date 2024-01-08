/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:00:53 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/08 18:03:49 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_nsx_byte
{
	char	bits;
	char	len;
}	t_nsx_byte;

void	_nsx_pc(char c);
void	_nsx_ps(char *str);
void	_nsx_pd(int n);
void	_nsx_pcolor(char color);
void	_nsx_ps_exit(char *_msg, int status, char color);

int		_nsx_atoi(char *str);
void	_nsx_putbanner(int pid, char *type);
void	handle_errors(int argc, char **argv, int pid);
#endif