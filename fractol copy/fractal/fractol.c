/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-meij <bde-meij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:21:19 by bde-meij          #+#    #+#             */
/*   Updated: 2022/05/27 18:03:46 by bde-meij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(t_fruct *fs)
{
	while (fs->y < HEIGHT)
	{
		while (fs->x < WIDTH)
		{
			fs->xtmp = fs->x * fs->zum * 4 / WIDTH - (2 * fs->zum - fs->movx);
			fs->ytmp = fs->y * fs->zum * 4 / HEIGHT - (2 * fs->zum - fs->movy);
			while (hypot(fs->xtmp, fs->ytmp) <= 2 && fs->i < 50)
			{
				fs->xp = fs->xtmp;
				fs->yp = fs->ytmp;
				fs->xtmp = (fs->xp * fs->xp) - (fs->yp * fs->yp) + \
					fs->x * fs->zum * 4 / WIDTH - (2 * fs->zum - fs->movx);
				fs->ytmp = 2 * fs->xp * fs->yp + \
					fs->y * fs->zum * 4 / HEIGHT - (2 * fs->zum - fs->movy);
				fs->i++;
			}
			mlx_put_pixel(fs->g_img, fs->x, fs->y, fs->colpal[fs->i % 11]);
			if (fs->i == 50)
				mlx_put_pixel(fs->g_img, fs->x, fs->y, 0x00000000);
			fs->i = 0;
			fs->x++;
		}
		fs->x = 0;
		fs->y++;
	}
}

void	julias(t_fruct *fs, double xco, double yco)
{
	while (fs->y < HEIGHT)
	{
		while (fs->x < WIDTH)
		{
			fs->xtmp = fs->x * fs->zum * 4 / WIDTH - (2 * fs->zum - fs->movx);
			fs->ytmp = fs->y * fs->zum * 4 / HEIGHT - (2 * fs->zum - fs->movy);
			while (hypot(fs->xtmp, fs->ytmp) <= 2 && fs->i < 300)
			{
				fs->xp = fs->xtmp;
				fs->yp = fs->ytmp;
				fs->xtmp = (fs->xp * fs->xp) - (fs->yp * fs->yp) + xco;
				fs->ytmp = 2 * fs->xp * fs->yp + yco;
				fs->i++;
			}
			mlx_put_pixel(fs->g_img, fs->x, fs->y, \
				fs->colpal[fs->i / 6 % 4 + 4]);
			if (fs->i < 16)
				mlx_put_pixel(fs->g_img, fs->x, fs->y, 0x00000000);
			fs->i = 0;
			fs->x++;
		}
		fs->x = 0;
		fs->y++;
	}
}

void	burningship(t_fruct *fs)
{
	while (fs->y < HEIGHT)
	{
		while (fs->x < WIDTH)
		{
			fs->xtmp = fs->x * fs->zum * 4 / WIDTH - (2 * fs->zum - fs->movx);
			fs->ytmp = fs->y * fs->zum * 4 / HEIGHT - (2 * fs->zum - fs->movy);
			while (hypot(fs->xtmp, fs->ytmp) <= 2 && fs->i < 80)
			{
				fs->xp = fs->xtmp;
				fs->yp = fs->ytmp;
				fs->xtmp = (fs->xp * fs->xp) - (fs->yp * fs->yp) + \
					fs->x * fs->zum * 4 / WIDTH - (2 * fs->zum - fs->movx);
				fs->ytmp = fabs(2 * fs->xp * fs->yp) + \
					fs->y * fs->zum * 4 / HEIGHT - (2 * fs->zum - fs->movy);
				fs->i++;
			}
			mlx_put_pixel(fs->g_img, fs->x, fs->y, fs->colpal[fs->i / 8 % 3]);
			if ((fs->i == 80) || (fs->i < 5))
				mlx_put_pixel(fs->g_img, fs->x, fs->y, 0x00000000);
			fs->i = 0;
			fs->x++;
		}
		fs->x = 0;
		fs->y++;
	}
}

double	ft_atof(const char *str)
{
	int		powa;
	int		index;
	double	value;
	double	sign;

	powa = 0;
	index = 0;
	value = 0;
	sign = 1;
	if (str[index] == '-')
	{
		sign = -1;
		index++;
	}
	while ((str[index] >= '0' && str[index] <= '9') || str[index] == '.')
	{
		if ((str[index - 1] == '.') || (powa > 0))
			powa += 1;
		if (str[index] != '.')
			value = value * 10 + (str[index] - 48);
		index++;
	}
	return ((value * sign) / pow(10, powa));
}
