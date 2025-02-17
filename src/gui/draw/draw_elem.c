/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_elem.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 17:28:28 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/06 12:12:01 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_video.h>
#include <SDL2/SDL_error.h>

#include "libft/ft_mem.h"

#include "gui_internal.h"
#include "sdl_extra.h"
#include "error.h"

/*
** * Gui internal function
*/

static t_bool	child_moved(t_transform *elem)
{
	t_transform	*cur;

	cur = elem->gui_elem.panel->children;
	while (cur != NULL)
	{
		if (cur->moved == TRUE)
			return (TRUE);
		cur = cur->next;
	}
	return (FALSE);
}

static void		update_pos_dim(t_transform *elem)
{
	SDL_Point	parent_dim;
	SDL_Point	parent_pos;

	if (elem->parent_type == ELEM)
	{
		ft_memcpy(&parent_pos, &elem->parent.elem->abs_pos, sizeof(SDL_Point));
		ft_memcpy(&parent_dim, &elem->parent.elem->abs_dim, sizeof(SDL_Point));
	}
	else
	{
		ft_memcpy(&parent_pos, &(SDL_Point){0, 0}, sizeof(SDL_Point));
		parent_dim.x = elem->parent.ui->window_surface->w;
		parent_dim.y = elem->parent.ui->window_surface->h;
	}
	elem->rel_pos.x = parent_dim.x * elem->pos.x;
	elem->rel_pos.y = parent_dim.y * elem->pos.y;
	elem->abs_dim.x = parent_dim.x * elem->dim.x;
	elem->abs_dim.y = parent_dim.y * elem->dim.y;
	elem->abs_pos.x = parent_pos.x + elem->rel_pos.x;
	elem->abs_pos.y = parent_pos.y + elem->rel_pos.y;
}

static void		reset_surface(t_transform *elem)
{
	if (elem->surface != NULL)
	{
		if (elem->abs_dim.x == elem->surface->w
		&& elem->abs_dim.y == elem->surface->h)
		{
			sdl_clear_surface(elem->surface);
			return ;
		}
		SDL_FreeSurface(elem->surface);
	}
	elem->surface = sdl_create_surface_default(elem->abs_dim);
}

static void		draw_gui_elem(t_transform *elem, t_game *game)
{
	SDL_Surface	*dst;

	dst = elem->surface;
	if (elem->gui_type == TEXT)
		draw_text(dst, elem->gui_elem.text, elem->abs_dim);
	else if (elem->gui_type == IMAGE)
		draw_image(dst, elem->gui_elem.image);
	else if (elem->gui_type == BUTTON)
		draw_button(dst, elem->gui_elem.button, elem->abs_dim);
	else if (elem->gui_type == GVIEW)
		draw_gview(dst, game);
	else if (elem->gui_type == MAP_EDITOR)
		draw_map_editor(dst, game, elem);
	else if (elem->gui_type == PANEL)
	{
		draw_panel(elem->gui_elem.panel, game);
		elem->has_alpha = sdl_has_surface_alpha(elem->surface);
	}
}

void			*draw_elem(t_transform *elem, t_game *game)
{
	if (elem->redraw == TRUE || elem->moved == TRUE)
		update_pos_dim(elem);
	if (elem->redraw == TRUE || (elem->gui_type == PANEL && child_moved(elem)))
	{
		reset_surface(elem);
		draw_gui_elem(elem, game);
	}
	elem->redraw = FALSE;
	elem->moved = FALSE;
	return (elem);
}
