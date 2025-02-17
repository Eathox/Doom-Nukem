/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_msg_sdl.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 13:54:59 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:49:49 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include "error.h"

void	error_msg_sdl(int error_code, const char *msg)
{
	error_msg(SDL_GetError(), error_code, msg);
}
