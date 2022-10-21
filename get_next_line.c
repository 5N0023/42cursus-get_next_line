#include "get_next_line.h"
#include<string.h>
#define BUFFER_SIZE 30



int	ft_check(char *buffer1)
{
	size_t i = 0;
	if (buffer1[0] == '\n')
		return 1;
	while (buffer1[i])
	{
		if (buffer1[i] == '\n')
			return i;
	i++;
	}
	return 0;
}
char *get_next_line(int fd)
{
	size_t i = 0;
	static size_t line = 0;
	static size_t call = 0;
	

	char *buffer1 = malloc(BUFFER_SIZE);
	char *res = NULL;

	while (read(fd,buffer1,BUFFER_SIZE))
	{
		if (ft_check(buffer1) != 0)
		{
			i = ft_check(buffer1);
			buffer1 = ft_substr(buffer1,0,i+1);
			line++;
		}
		res = ft_strjoin(res,buffer1);
		free(buffer1);
		if (line == call)
		{
			call++;
			return res;
		}
		/*free(res);
		res = NULL;*/
	}
	return 0;
}
int main()
{ 
	
	int fd = open("test.txt", O_RDONLY);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	
	return 0;
}