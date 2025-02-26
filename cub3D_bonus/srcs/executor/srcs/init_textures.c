/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:58:48 by sahafid           #+#    #+#             */
/*   Updated: 2022/09/30 21:52:05 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	init_sprite(t_graph *lst)
{
	lst->sprite.sprite = mlx_xpm_file_to_image(lst->mlx, \
	"srcs/textures/chest.xpm", &lst->sprite.widthsprite, \
	&lst->sprite.heightsprite);
	lst->sprite.addrsprite = (int *)mlx_get_data_addr(lst->sprite.sprite, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	if (lst->sprite.sprite == NULL || lst->sprite.addrsprite == NULL)
		exit (1);
}

void	init_door(t_graph *lst)
{
	lst->door.door1_img = mlx_xpm_file_to_image(lst->mlx, \
	"srcs/textures/door1.xpm", &lst->door.widthdoor1, &lst->door.heightdoor1);
	lst->door.door1_txtr = (int *)mlx_get_data_addr(lst->door.door1_img, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	if (lst->door.door1_img == NULL || lst->door.door1_txtr == NULL)
		exit (1);
	lst->door.door2_img = mlx_xpm_file_to_image(lst->mlx, \
	"srcs/textures/door2.xpm", &lst->door.widthdoor2, &lst->door.heightdoor2);
	lst->door.door2_txtr = (int *)mlx_get_data_addr(lst->door.door2_img, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	if (lst->door.door2_img == NULL || lst->door.door2_txtr == NULL)
		exit (1);
	lst->door.door3_img = mlx_xpm_file_to_image(lst->mlx, \
	"srcs/textures/door3.xpm", &lst->door.widthdoor3, &lst->door.heightdoor3);
	lst->door.door3_txtr = (int *)mlx_get_data_addr(lst->door.door3_img, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	if (lst->door.door3_img == NULL || lst->door.door3_txtr == NULL)
		exit (1);
	lst->door.door4_img = mlx_xpm_file_to_image(lst->mlx, \
	"srcs/textures/door4.xpm", &lst->door.widthdoor4, &lst->door.heightdoor4);
	lst->door.door4_txtr = (int *)mlx_get_data_addr(lst->door.door4_img, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	lst->door.door_number = 1;
	if (lst->door.door4_img == NULL || lst->door.door4_txtr == NULL)
		exit (1);
}

void	init_texture(t_graph *lst, t_map_ *data)
{
	lst->texture.textureimgn = mlx_xpm_file_to_image(lst->mlx, data->no_t, \
	&lst->texture.widthn, &lst->texture.heightn);
	lst->texture.imgaddrn = (int *)mlx_get_data_addr(lst->texture.textureimgn, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	if (lst->texture.textureimgn == NULL || lst->texture.imgaddrn == NULL)
		exit (1);
	lst->texture.textureimgs = mlx_xpm_file_to_image(lst->mlx, data->so_t, \
	&lst->texture.widths, &lst->texture.heights);
	lst->texture.imgaddrs = (int *)mlx_get_data_addr(lst->texture.textureimgs, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	if (lst->texture.textureimgs == NULL || lst->texture.imgaddrs == NULL)
		exit (1);
	lst->texture.textureimge = mlx_xpm_file_to_image(lst->mlx, data->ea_t, \
	&lst->texture.widthe, &lst->texture.heighte);
	lst->texture.imgaddre = (int *)mlx_get_data_addr(lst->texture.textureimge, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	if (lst->texture.textureimge == NULL || lst->texture.imgaddre == NULL)
		exit (1);
	lst->texture.textureimgw = mlx_xpm_file_to_image(lst->mlx, data->we_t, \
	&lst->texture.widthw, &lst->texture.heightw);
	lst->texture.imgaddrw = (int *)mlx_get_data_addr(lst->texture.textureimgw, \
	&lst->texture.bpp, &lst->texture.size_line, &lst->texture.endian);
	if (lst->texture.textureimgw == NULL || lst->texture.imgaddrw == NULL)
		exit (1);
}
