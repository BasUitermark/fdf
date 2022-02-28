#include "parse.h"

int	main(void)
{
	char	*map;

	map = parse_map("../../maps/42.fdf");
	printf("%s\n", map);
}
