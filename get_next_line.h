/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlektaib <mlektaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:35:56 by mlektaib          #+#    #+#             */
/*   Updated: 2022/10/27 00:39:35 by mlektaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;
char	*get_next_line(int fd);
int		read_file(int fd, int *readed, t_list **buffer);
void	add_tolist(char *content, t_list **buffer, int readed);
char	*extract_line(t_list *buffer);
void	allocline(t_list *buffer, char **line);
int		ft_check(t_list *buffer);
size_t	ft_strlen(const char *str);
void	ft_lstclear(t_list **lst);
void	make_remain(t_list **head);
t_list	*ft_lstlast(t_list *lst);

#endif
