/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:45:28 by bde-meij          #+#    #+#             */
/*   Updated: 2022/05/27 18:32:58 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ini_struct(t_fruct *fs, char **av, int ac)
{
	fs->i = 0;
	fs->x = 0;
	fs->y = 0;
	fs->yp = 0;
	fs->xp = 0;
	fs->zum = 1;
	fs->xtmp = 0;
	fs->ytmp = 0;
	fs->movx = 0;
	fs->movy = 0;
	fs->mousx = 0;
	fs->mousy = 0;
	fs->arg = av;
	fs->arc = ac;
	fs->colpal[0] = 0x800008FF;
	fs->colpal[1] = 0xFF0008FF;
	fs->colpal[2] = 0xFFFF44FF;
	fs->colpal[3] = 0xFF00FFFF;
	fs->colpal[4] = 0xFFAC1CFF;
	fs->colpal[5] = 0xF28C28FF;
	fs->colpal[6] = 0x00A36CFF;
	fs->colpal[7] = 0x7DF9FFFF;
	fs->colpal[8] = 0x006400FF;
	fs->colpal[9] = 0xBDB76BFF;
	fs->colpal[10] = 0x008080FF;
}

int	display_options(int gen_value)
{
	if (gen_value == 0)
	{
		ft_putstr_fd("\noh no! invalid input\n\n\
options are: 'mandelbrot', 'julia_one',\n'julia_two',\
'julia_three' and 'burningship'\n\
OR... you can give two values ranging from '-2' to '2'\n\
example: ./fractol -0.65 1.02\n\n", 1);
	}
	else
		ft_putstr_fd("\nwelcome to my fractal explorer!\n\n\
Controls are: arrow keys for movement,\n\
'z' and 'x' will zoom to/from current centre,\n\
while mousewheel will zoom to mouseposition.\n\
Press 'c' and 'v' quickly to !*** DISCO ***!\n\n\
press 'r' to restart position, or hit 'escape' to quit.\n\n", 1);
	return (gen_value);
}

int	checkiftof(const char *str)
{
	size_t	i;
	int		dot;

	i = 0;
	dot = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || \
		(str[i] == '-' && i == 0))
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (i != ft_strlen(str) || dot > 1)
		return (-2);
	return (0);
}

int	generate_fractal(t_fruct *fs)
{
	fs->x = 0;
	fs->y = 0;
	if (ft_strncmp(fs->arg[1], "mandelbrot", 100) == 0)
		mandelbrot(fs);
	else if (ft_strncmp(fs->arg[1], "julia_one", 100) == 0)
		julias(fs, 0.355, -0.355);
	else if (ft_strncmp(fs->arg[1], "julia_two", 100) == 0)
		julias(fs, 0, 0.8);
	else if (ft_strncmp(fs->arg[1], "julia_three", 100) == 0)
		julias(fs, 0.4, -0.59);
	else if ((fs->arc == 3) && (checkiftof(fs->arg[1]) != -2) \
		&& (checkiftof(fs->arg[2]) != -2))
		julias(fs, ft_atof(fs->arg[1]), ft_atof(fs->arg[2]));
	else if (ft_strncmp(fs->arg[1], "burningship", 100) == 0)
		burningship(fs);
	else
		return (0);
	return (1);
}

int32_t	main(int ac, char **av)
{
	t_fruct	fs;

	if ((ac < 2) || (ac > 3))
		return (ft_putstr_fd("invalid number of arguments\n", 1), 0);
	ini_struct(&fs, av, ac);
	fs.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!fs.mlx)
		exit(EXIT_FAILURE);
	fs.g_img = mlx_new_image(fs.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(fs.mlx, fs.g_img, 0, 0);
	if (display_options(generate_fractal(&fs)) != 0)
	{
		mlx_key_hook(fs.mlx, &my_keyhook, (void *)&fs);
		mlx_scroll_hook(fs.mlx, &my_scrollhook, (void *)&fs);
		mlx_loop(fs.mlx);
	}
	mlx_delete_image(fs.mlx, fs.g_img);
	mlx_terminate(fs.mlx);
	return (EXIT_SUCCESS);
}
