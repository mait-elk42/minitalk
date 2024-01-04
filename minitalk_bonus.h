/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:00:53 by mait-elk          #+#    #+#             */
/*   Updated: 2024/01/04 18:43:57 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_nsx_byte
{
	char	bits;
	char	len;
}	t_nsx_byte;

void	_nsx_pc(char c);
void	_nsx_ps(char *str);
void	_nsx_pd(int n);
void	_nsx_pd(int n);
void	_nsx_p(char	*f, ...);
void	_nsx_pcolor(char color);

int		_nsx_atoi(char *str);
#endif