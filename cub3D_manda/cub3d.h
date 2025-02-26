/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:55:26 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/30 18:57:09 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

/* --------------------------------------------------------------- */

typedef struct s_mapdata
{
	char	**map;
	int		map_hight;
	int		map_width;
	int		fst_line;
	int		count_player;
	int		player_x;
	int		player_y;
}	t_mapData;

/* --------------------------------------------------------------- */

typedef struct s_map_
{
	char		*no_t;
	char		*so_t;
	char		*we_t;
	char		*ea_t;
	int			no_fd;
	int			so_fd;
	int			we_fd;
	int			ea_fd;
	int			fd;
	int			ceil_color;
	int			floor_color;
	t_mapData	map_d;

}	t_map_;

/* --------------------------------------------------------------- */

int		parser(char **argv, t_map_ *data);
void	executor(t_map_ *data);
void	free_all(t_map_ *data, char *str);

#endif
