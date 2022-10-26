/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:34:16 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/26 20:59:39 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*buffer;
	int				readed;
	char			*line;

	readed = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (0);
	read_file(fd, &readed, &buffer);
	line = extract_line(buffer);
	if (line)
		make_remain(&buffer);
	return (line);
}

int	read_file(int fd, int *readed, t_list **buffer)
{
	char	*content;

	while (ft_check(*buffer) != 1 && *readed > 0)
	{
		content = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!content)
			return (0);
		*readed = (int)read(fd, content, BUFFER_SIZE);
		if (*readed <= 0)
		{
			free(content);
			break ;
		}
		add_tolist(content, buffer, *readed);
		free(content);
	}
	return (1);
}

void	add_tolist(char *content, t_list **buffer, int readed)
{
	t_list	*newnode;
	int		i;
	t_list	*last;

	i = -1;
	if (!content || read <= 0 || !buffer)
		return ;
	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return ;
	newnode->content = malloc(sizeof(char) * (readed + 1));
	if (!newnode->content)
		return ;
	while (i++ < readed)
		newnode->content[i] = content[i];
	newnode->content[i] = 0;
	newnode->next = NULL;
	last = ft_lstlast(*buffer);
	if (!last)
		*buffer = newnode;
	else
		last->next = newnode;
}

char	*extract_line(t_list *buffer)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!buffer)
		return (0);
	allocline(buffer, &line);
	if (!line)
		return (0);
	while (buffer)
	{
		j = 0;
		while (buffer->content[j] != '\n' && buffer->content[j])
					line[i++] = buffer->content[j++];
		if (buffer->content[j] == '\n')
			line[i++] = '\n';
		buffer = buffer->next;
	}
	line[i] = 0;
	return (line);
}

void	allocline(t_list *buffer, char **line)
{
	size_t	count;
	size_t	i;
	int		nl;

	count = 0;
	i = 0;
	nl = 0;
	if (!buffer)
		return ;
	while (buffer)
	{
		i = 0;
		while (buffer->content[i] != '\n' && buffer->content[i++])
				count++;
		if (buffer->content[i] == '\n')
			nl = 1;
		buffer = buffer->next;
	}
	if (count == 0 && nl != 1)
	{
		*line = 0;
		return ;
	}
	count++;
	*line = malloc(sizeof(char) * count +1);
}
