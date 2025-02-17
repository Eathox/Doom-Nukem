/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sdl_clear_surface.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/17 13:54:06 by jvisser       #+#    #+#                 */
/*   Updated: 2020/04/06 12:04:07 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_surface.h>

#include "libft/ft_mem.h"

void	sdl_clear_surface(SDL_Surface *surface)
{
	ft_bzero(surface->pixels, surface->pitch * surface->h);
}
