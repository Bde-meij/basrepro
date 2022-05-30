/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:48:02 by bde-meij          #+#    #+#             */
/*   Updated: 2022/05/27 18:33:58 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	shiftcol(t_fruct *fs, int keyval)
{
	int	i;
	int	mod;

	i = 0;
	mod = 0;
	if (keyval == MLX_KEY_C)
		mod = 80000;
	else if (keyval == MLX_KEY_V)
		mod = -80000;
	while (i < 12)
	{
		fs->colpal[i] += mod;
		i++;
	}
}

void	my_scrollhook(double xdelta, double ydelta, void *fs)
{
	double	xmous;
	double	ymous;

	mlx_get_mouse_pos(((t_fruct *)fs)->mlx, &((t_fruct *)fs)->mousx, \
		&((t_fruct *)fs)->mousy);
	xmous = ((t_fruct *)fs)->mousx;
	ymous = ((t_fruct *)fs)->mousy;
	xdelta = 0;
	if (ydelta > 0)
	{
		((t_fruct *)fs)->zum *= 0.8;
		((t_fruct *)fs)->movx += ((xmous / WIDTH) - .5) * ((t_fruct *)fs)->zum;
		((t_fruct *)fs)->movy += ((ymous / HEIGHT) - .5) * ((t_fruct *)fs)->zum;
	}
	else if (ydelta < 0)
	{
		((t_fruct *)fs)->movx -= ((xmous / WIDTH) - .5) * ((t_fruct *)fs)->zum;
		((t_fruct *)fs)->movy -= ((ymous / HEIGHT) - .5) * ((t_fruct *)fs)->zum;
		((t_fruct *)fs)->zum /= 0.8;
	}
	generate_fractal((t_fruct *)fs);
}

void	my_keyhook(mlx_key_data_t keydata, void *fs)
{
	if (keydata.key == 262 && keydata.action == 1)
		((t_fruct *)fs)->movx += .5 * ((t_fruct *)fs)->zum;
	else if (keydata.key == 263 && keydata.action == 1)
		((t_fruct *)fs)->movx -= .5 * ((t_fruct *)fs)->zum;
	else if (keydata.key == 264 && keydata.action == 1)
		((t_fruct *)fs)->movy += .5 * ((t_fruct *)fs)->zum;
	else if (keydata.key == 265 && keydata.action == 1)
		((t_fruct *)fs)->movy -= .5 * ((t_fruct *)fs)->zum;
	else if (keydata.key == MLX_KEY_Z && keydata.action == 1)
		((t_fruct *)fs)->zum *= .8;
	else if (keydata.key == MLX_KEY_X && keydata.action == 1)
		((t_fruct *)fs)->zum /= .8;
	else if (keydata.key == MLX_KEY_R && keydata.action == 1)
		ini_struct(((t_fruct *)fs), ((t_fruct *)fs)->arg, ((t_fruct *)fs)->arc);
	else if ((keydata.key == MLX_KEY_C || keydata.key == MLX_KEY_V) && \
		keydata.action == 1)
		shiftcol(((t_fruct *)fs), keydata.key);
	else if (keydata.key == 256 && keydata.action == 1)
	{
		mlx_terminate(((t_fruct *)fs)->mlx);
		exit(0);
	}
	else
		return ;
	generate_fractal((t_fruct *)fs);
}
