/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-fagr <rel-fagr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 11:00:48 by rel-fagr          #+#    #+#             */
/*   Updated: 2022/09/30 16:51:02 by rel-fagr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser.h"

/* --------------------------------------------------------------- */

void	check_valid_line(t_map_ *data)
{
	int		i;
	int		j;
	char	c;

	i = -1;
	while (data->map_d.map[++i])
	{
		j = 0;
		if (check_empty_line(data, i))
			free_all(data, "map error!!");
		while (data->map_d.map[i][j])
		{
			c = data->map_d.map[i][j];
			if (c == '0' || c == 'W' || c == 'E' || c == 'N' || c == 'S')
				if (check_left_right(data->map_d.map[i], j) || \
					check_up_down(data, i, j))
					free_all(data, "map error!!");
			if (c == '0')
				check_door1(data, i, j);
			j++;
		}
	}
	check_door2(data);
}

/* --------------------------------------------------------------- */

void	check_text_col_data(t_map_ *data)
{
	if (data->no_t == NULL || data->so_t == NULL || data->ea_t == NULL || \
		data->we_t == NULL || data->ceil_color == -1 || data->floor_color == -1)
		free_all(data, "error!! bad map arg");
}

/* --------------------------------------------------------------- */

int	ft_check_map(t_map_	*data)
{
	char	*str;
	int		i;
	int		count;

	i = 0;
	count = 0;
	str = get_next_line(data->fd);
	while (str != NULL)
	{
		if (count < 6)
			process_data(str, data, &count);
		else
		{
			check_text_col_data(data);
			check_map(str, data, i);
		}
		i++;
		free(str);
		str = get_next_line(data->fd);
	}
	free(str);
	if (data->map_d.count_player == 0 || data->map_d.count_player > 1)
		free_all(data, "error!! bad player number");
	return (0);
}

/* --------------------------------------------------------------- */

int	init_map_data(t_map_ *data, char **argv)
{
	char	*str;

	data->no_t = NULL;
	data->so_t = NULL;
	data->ea_t = NULL;
	data->we_t = NULL;
	data->ceil_color = -1;
	data->floor_color = -1;
	data->map_d.map_hight = 0;
	data->map_d.map_width = 0;
	data->map_d.fst_line = 0;
	data->map_d.count_player = 0;
	data->map_d.map = NULL;
	str = ft_strrchr(argv[1], '.');
	if (str && !ft_strcmp(str, ".cub"))
	{
		data->fd = open(argv[1], O_RDONLY);
		if (data->fd < 0)
			return (write(1, "error!! bad .cub file\n", 22), 1);
	}
	else
		return (1);
	return (0);
}

/* --------------------------------------------------------------- */

int	parser(char **argv, t_map_ *data)
{
	if (init_map_data(data, argv) || ft_check_map(data))
		return (1);
	creat_map_array(data, argv);
	check_valid_line(data);
	virtual_wall(data);
	return (0);
}
