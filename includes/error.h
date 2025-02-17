/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 14:35:51 by jvisser       #+#    #+#                 */
/*   Updated: 2019/08/27 15:13:06 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	error_msg_errno(const char *msg);
void	error_msg_sdl(int error_code, const char *msg);
void	error_msg(const char *error_msg, int error_code, const char *msg);

#endif
