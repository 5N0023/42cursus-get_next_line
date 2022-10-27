/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:35:41 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/27 02:15:46 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	make_remain(t_list **buffer)
{
	t_list	*last;
	t_list	*remain_node;
	int		i;
	int		j;

	remain_node = malloc(sizeof(t_list));
	if (buffer == NULL || remain_node == NULL)
		return ;
	remain_node->next = NULL;
	last = ft_lstlast(*buffer);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	remain_node->content = malloc(((ft_strlen(last->content) - i) + 1));
	if (remain_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		remain_node->content[j++] = last->content[i++];
	remain_node->content[j] = '\0';
	ft_lstclear(buffer);
	*buffer = remain_node;
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!last)
		return (0);
	while (last->next)
	{
		last = last->next;
	}
	return (last);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst)
		return ;
	if (lst)
	{
		while (*lst)
		{
			temp = (*lst)->next;
			free((*lst)->content);
			free(*lst);
			*lst = temp;
		}
	}
	*lst = NULL;
}

int	ft_check(t_list *buffer)
{
	t_list	*last;
	size_t	i;

	i = 0;
	if (!buffer)
		return (0);
	last = ft_lstlast(buffer);
	while (last->content[i])
	{	
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
