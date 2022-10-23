/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 03:42:35 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/23 23:13:22 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;
	count = 0;

	while (str[count])
		count++;
	return (count);
}
char *ft_join1(char *buffer)
{
	size_t count = 0;
	size_t i = 0;
	char *res;
	while((buffer[count] != '\0' && buffer[count] != '\n') && count < BUFFER_SIZE)
		count++;
	count++;
	res = malloc(count+1);
	while(i < count)
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = 0;
	return res;
}

char *ft_join2(char *oldres,char *buffer,size_t n)
{
	size_t i = 0;
	size_t j = 0;
	char *res;
	res = malloc(n + ft_strlen(oldres)+1);
	while(i < ft_strlen(oldres))
	{
		res[i]=oldres[i];
		i++;
	}
	while(j < n)
	{
		res[i+j] = buffer[j];
		j++;
	}
	res[i+j] = 0;
	return res;
}
char *ft_join3(char *buffer,size_t l)
{
	char *res =NULL;
	size_t oldl = l;
	l = ft_check(buffer + oldl,l);
	res = ft_join1(buffer + oldl);
	return res;
}