#include "fdf.h"

static int	count_width(char *str_map)
{
	int	width_count;
	int	i;

	width_count = 0;
	i = 0;
	while (str_map[i] != '\n')
	{
		if (ft_isdigit(str_map[i]))
		{
			width_count++;
			while (ft_isdigit(str_map[i]))
				i++;
		}
		if (str_map[i] == ' ')
			i++;
		if (str_map[i] == ',')
			i += 9;
	}
	return (width_count);
}

static bool	validate_str_map(char *str_map, int depth_count)
{
	int	i;
	int	j;
	int	width_cur;
	int	width_prev;

	i = 0;
	j = 0;
	width_cur = -1;
	width_prev = -1;
	while (i < depth_count)
	{
		if (width_cur == -1 && width_prev == -1)
		{
			width_cur = count_width(&str_map[j]);
			width_prev = width_cur;
		}
		width_cur = count_width(&str_map[j]);
		j += width_cur;
		printf("%d# current:	%d\n", i + 1, width_cur);
		printf("%d# previous:	%d\n\n", i + 1, width_prev);
		if (width_cur != width_prev)
			return (FALSE);
		width_prev = width_cur;
		width_cur = 0;
		i++;
	}
	return (TRUE);
}

static int	process(char *str_map, int depth_count)
{
	int	map_data;

	map_data = 0;
	if (!validate_str_map(str_map, depth_count))
	{
		free(str_map);
		error(RED"Shit fucked"RESET);
	}

	return (map_data);
}

int	parse_map(char *filepath)
{
	int		fd;
	int		depth_count;
	char	*temp;
	char	*str_map;

	depth_count = 0;
	str_map = NULL;
	fd = open(filepath, O_RDONLY);
	if (fd < 0 || !ft_strnstr(filepath, ".fdf", ft_strlen(filepath)))
		error(RED"Invalid pathname! Needs to be \".fdf\""RESET);
	while (true)
	{
		temp = ft_get_next_line(fd);
		if (temp)
		{
			str_map = ft_strappend(str_map, temp);
			depth_count++;
		}
		else
			break ;
		free(temp);
	}
	close(fd);
	// printf("%s", str_map);
	return (process(str_map, depth_count));
}
