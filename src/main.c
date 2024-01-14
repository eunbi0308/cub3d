#include "cub3d.h"


double	position_to_degree(char p_direction)
{
	if (p_direction == 'N')
		return (deg2rad(90));
	else if (p_direction == 'E')
		return (deg2rad(0));
	else if (p_direction == 'W')
		return (deg2rad(180));
	else
		return (deg2rad(270));
}

int main(int argc, char **argv)
{
	t_data		data;
	//mlx_t		*mlx;
	// mlx_image_t	*image;

	if (!(data.mlx = mlx_init(SX, SY, "cub3d", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(data.image = mlx_new_image(data.mlx, SX, SY)))
	{
		mlx_close_window(data.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(data.mlx, data.image, 0, 0) == -1)
	{
		mlx_close_window(data.mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (argc != 2)
		err_msg("Wrong number of arguments");
	parser(argc, argv, &data.file);
		//err_msg("Parser has failded");
	init_player(&data);
	//mlx_key_hook(mlx, display, &data);
	mlx_key_hook(data.mlx, key_press, &data);
	mlx_loop(data.mlx);
	free(data.player);
	mlx_terminate(data.mlx);
}