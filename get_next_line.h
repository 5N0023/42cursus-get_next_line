#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

int	read_file(int fd,int *readed,t_list **buffer);
void add_tolist(char *content,t_list **buffer,int readed);
void	ft_lstadd_back(t_list **lst, t_list *new);
char *extract_line(t_list *buffer);
size_t alloccount(t_list *buffer);
int ft_check(t_list *buffer);
size_t	ft_strlen(const char *str);
void	ft_lstclear(t_list **lst);
void make_remain(t_list **head);
t_list	*ft_lstlast(t_list *lst);

#endif