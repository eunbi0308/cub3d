/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   seperate_file_content.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@42.fr>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 12:05:12 by gozturk       #+#    #+#                 */
/*   Updated: 2024/02/06 13:43:41 by eucho         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_texture_type(t_file *file, char *line, char *texture)
{
	if (ft_strsame(texture, line) == 1 && (!file->identifier.floor_set
			|| !file->identifier.ceiling_set || !file->identifier.no_set
			|| !file->identifier.so_set || !file->identifier.we_set
			|| !file->identifier.ea_set))
	{
		err_msg("Cannot identify content");
	}
	if (ft_strsame(texture, "NO") == 1
		|| ft_strsame(texture, "SO") == 1
		|| ft_strsame(texture, "WE") == 1
		|| ft_strsame(texture, "EA") == 1)
		return (true);
	return (false);
}

bool	is_color_type(t_file *file, char *line, char *color)
{
	if (ft_strsame(color, line) == 1 && (!file->identifier.floor_set
			|| !file->identifier.ceiling_set || !file->identifier.no_set
			|| !file->identifier.so_set || !file->identifier.we_set
			|| !file->identifier.ea_set))
		err_msg("Cannot identify content");
	if (ft_strsame(color, "F") == 1
		|| ft_strsame(color, "C") == 1)
		return (true);
	return (false);
}

/*
** Checks if all directions and color identifiers are set
*/
bool	identifiers_complete(t_file *file)
{
	return (file->identifier.no_set == false
		|| file->identifier.so_set == false
		|| file->identifier.we_set == false
		|| file->identifier.ea_set == false
		|| file->identifier.floor_set == false
		|| file->identifier.ceiling_set == false);
}

void	comma_counter(char *line)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		err_msg("Color value error");
}

/*
** Traverse in file content array (char arr) and seperates
** identifier information and creates map array
*/
int	handle_content(t_file *file, int r, int row)
{
	char	**temp_arr;

	temp_arr = NULL;
	while (file->content_arr[r] != NULL)
	{
		temp_arr = ft_split(file->content_arr[r], ' ');
		if (temp_arr == NULL)
			return (EXIT_FAILURE);
		if (is_texture_type(file, file->content_arr[r], temp_arr[0]) == 1)
			set_textures(file, temp_arr);
		else if (is_color_type(file, file->content_arr[r], temp_arr[0]) == 1)
			set_colors(file, file->content_arr[r], temp_arr);
		else
			create_map(file, file->content_arr[r], &row);
		free_arr(temp_arr);
		r++;
	}
	last_check_content(file);
	return (EXIT_SUCCESS);
}
