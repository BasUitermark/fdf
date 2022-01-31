#include "../include/fdf.h"

char	*ft_convert(char *str)
{
	
}

char	*ft_parse(char *filepath)
{
	int	fd;
	char	*temp;
	char	*out;

	out = NULL;
	fd = open(filepath, O_RDONLY);
	while (true)
	{
		temp = ft_get_next_line(fd);
		if (temp)
		{
			out = ft_strappend(out, temp);
		}
		else
			break ;
		free(temp);
	}
	close(fd);
	return (ft_convert);
}