/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:06:01 by gozturk       #+#    #+#                 */
/*   Updated: 2024/02/05 15:58:01 by eucho         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_data *data)
{
	data->pl = (t_player *)malloc(sizeof(t_player));
	data->pl->x = data->file.map.player_pos_x;
	data->pl->y = data->file.map.player_pos_y - 1.0;
	data->pl->th = position_to_degree(data->file.map.p_direction);
}

void	init_identifiers(t_file *file)
{
	file->identifier.path_no = NULL;
	file->identifier.no_set = false;
	file->identifier.path_so = NULL;
	file->identifier.so_set = false;
	file->identifier.path_we = NULL;
	file->identifier.we_set = false;
	file->identifier.path_ea = NULL;
	file->identifier.ea_set = false;
	file->identifier.ceiling_set = false;
	file->identifier.floor_set = false;
	file->identifier.number_of_lines = 0;
	file->identifier.f_r = 0;
	file->identifier.f_g = 0;
	file->identifier.f_b = 0;
	file->identifier.c_r = 0;
	file->identifier.c_g = 0;
	file->identifier.c_b = 0;
}

void	init_map(t_file *file)
{
	file->map.row = 0;
	file->map.column = 0;
	file->map.p_direction = '0';
	file->map.player_pos_x = -1;
	file->map.player_pos_y = -1;
	file->map.map_arr = NULL;
	file->map.copy_arr = NULL;
	file->map.map_int_arr = NULL;
}

void	init_file_struct(t_file *file)
{
	file->total_lines = 0;
	file->content_arr = NULL;
	init_identifiers(file);
	init_map(file);
}
