#include "/usr/include/minilibx-linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int x = 5;
	int y = 720;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (x < 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
	}
	while (x < 200)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF7700);
		x++;
	}
	while (x < 300)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FFFF00);
		x++;
	}
	while (x < 400)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF00);
		x++;
	}
	while (x < 500)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FF77);
		x++;
	}
	while (x < 600)
	{
		my_mlx_pixel_put(&img, x, y, 0x0000FFFF);
		x++;
	}
	while (x < 700)
	{
		my_mlx_pixel_put(&img, x, y, 0x000000FF);
		x++;
	}
	while (x < 800)
	{
		my_mlx_pixel_put(&img, x, y, 0x007700FF);
		x++;
	}
	while (x < 900)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF00FF);
		x++;
	}
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

