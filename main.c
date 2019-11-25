#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int		file;
	int		rslt; 
	char	*str;	
	
	file = open("test.txt", O_RDONLY);
	while ((rslt = get_next_line(file, &str) == 1))
	{
		printf("%d:%s\n", rslt, str);
		free(str);
	}
	return(0);
}