/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozturk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:06:07 by gozturk           #+#    #+#             */
/*   Updated: 2024/01/31 12:06:13 by gozturk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <assert.h>

/*
**  PRINT STATEMENTS FOR TESTING PURPOSE
*/

// void print_file_content(t_file *file)
// {
// 	for(int i = 0; i < 20; i++)
// 	{
// 		printf("%s\n", file->content_arr[i]);
// 	}
// 	printf("file->total_lines = %d\n", file->total_lines);
// }

//void	print_2d_map(t_data *data)
// {
// 	int	i;
// 	for(int y = 0; y < data->file.map.row; y++) 
// 	{
// 		i = data->file.map.row - 1 - y;
// 		for(int x = 0; x < (int)ft_strlen(data->file.map.map_arr[i]); x++ )
// 		{
// 			int	result = get_cell_value(data, x, y);
// 			if (result == 1)
// 				printf("1");
// 			else if (result >= 1)
// 				printf(" ");
// 			else
// 				printf("0");
// 		}
// 		putchar('\n');
// 	}
// }

void	print_texture_paths(t_file *file)
{
	printf("texture path NO = %s\n", file->identifier.path_no);
	printf("texture path SO = %s\n", file->identifier.path_so);
	printf("texture path WE = %s\n", file->identifier.path_we);
	printf("texture path EA = %s\n", file->identifier.path_ea);
}

void	print_colors(t_file *file)
{
	printf("colors floor = %d, %d, %d\n",
		file->identifier.f_r, file->identifier.f_g, file->identifier.f_b);
	printf("colors ceiling = %d, %d, %d\n",
		file->identifier.c_r, file->identifier.c_g, file->identifier.c_b);
}

void	print_map(t_file *file)
{
	int	i;

	i = 0;
	while (i < file->total_lines)
	{
		printf("%s\n", file->map.map_arr[i]);
		i++;
	}
	printf("pl r = %lf\nplayer c = %lf\nchar = %c\n",
		file->map.player_pos_x, file->map.player_pos_y,
		file->map.p_direction);
}

void	print_int_map(t_file *file)
{
	int	r;
	int	c;

	r = 0;
	c = 0;
	while (r < file->map.row)
	{
		c = 0;
		while (c < (int)ft_strlen(file->map.map_arr[r]))
		{
			printf("%d\n", file->map.map_int_arr[r][c]);
			c++;
		}
		r++;
	}
}
