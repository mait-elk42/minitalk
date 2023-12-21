/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mait-elk <mait-elk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:00:53 by mait-elk          #+#    #+#             */
/*   Updated: 2023/12/21 19:20:14 by mait-elk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	_nsx_pc(char c);
void	_nsx_ps(char *str);
void	_nsx_pd(int n);
void	_nsx_pd(int n);
void	_nsx_p(char	*f, ...);
void	_nsx_pcolor(char color);

int		_nsx_atoi(char *str);
#endif