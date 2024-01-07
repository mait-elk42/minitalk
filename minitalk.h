/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:00:53 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/07 11:14:46 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_nsx_byte
{
	int	bits;
	int	len;
}	t_nsx_byte;

void	_nsx_pc(char c);
void	_nsx_ps(char *str);
void	_nsx_pd(int n);
void	_nsx_pd(int n);
void	_nsx_pcolor(char color);
void	_nsx_ps_exit(char *_msg, int status, char color);

int		_nsx_atoi(char *str);
#endif