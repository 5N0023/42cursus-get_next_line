/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:41:06 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/23 23:33:56 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	ft_check(char *buff,size_t l)
{
	size_t i = 0;
	while(i < BUFFER_SIZE)
	{
		if (buff[i] == '\n')
		{
			l = i;
			return (i);	
		}	i++;

	}
	l = 0;
	return 0;
}



char *get_next_line(int fd)
{
	char *buffer = NULL;
	static	size_t l = 0;
	static size_t call = 0;
	char *p = NULL;
	
	if (!buffer)
		buffer = malloc(BUFFER_SIZE);
	call++;
	if (call == 1)
	{	
		p = ft_getfirstline(fd,l,buffer);
		l = ft_check(buffer,l);
		printf("|||%zu|||",l);
		return (p);
	}
	if (call > 1)
	{
		p = ft_getnewline(fd,l,buffer);
		l = ft_check(buffer,l);
		return p;
	}
	
	return 0;
}
int main()
{
	int fd = open("test",O_RDONLY);
	printf("%s |||\n",get_next_line(fd));
}