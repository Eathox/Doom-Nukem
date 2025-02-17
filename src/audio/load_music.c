/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_music.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/25 17:28:18 by ehollidg      #+#    #+#                 */
/*   Updated: 2020/04/16 13:15:22 by euan          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL_mixer.h>

#include "libft/ft_mem.h"

#include "game.h"
#include "audio.h"
#include "error.h"

static void	addmusic(t_hashmap *sound_map,
									char *const name, char const *exec_path)
{
	add_track_to_map(sound_map, get_music_from_mp3(name, exec_path), name);
}

void		load_music(t_hashmap *music_map, char const *exec_path)
{
	addmusic(music_map, "lonely_troutman_ii", exec_path);
	addmusic(music_map, "asking_questions", exec_path);
	addmusic(music_map, "hit_n_smash", exec_path);
	addmusic(music_map, "EnemiesLOOP", exec_path);
}
