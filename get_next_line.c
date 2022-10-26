#include "get_next_line.h"



char *get_next_line(int fd)
{
	static t_list *buffer = NULL;
	int readed = 1;
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd,&line,0) < 0)
		return 0;
	read_file(fd,&readed,&buffer);
	line = extract_line(buffer);
	if (line)
		make_remain(&buffer);
	return(line);

}

int	read_file(int fd,int *readed,t_list **buffer)
{
	char *content;


	while(ft_check(*buffer) != 1 && *readed > 0)
		{
			content = malloc((BUFFER_SIZE+1)*sizeof(char));
			*readed = (int)read(fd,content,BUFFER_SIZE);
			if(*readed <= 0)
			{
				free(content);
				break;
			}
			add_tolist(content,buffer,*readed);
		}
	return 1;

}

void add_tolist(char *content,t_list **buffer,int readed)
{
	t_list *newnode;
	int i = 0;
	t_list *last;

	if(!content || read <= 0 || !buffer)
		return;
	newnode = malloc(sizeof(t_list));
	newnode->content = malloc(sizeof(char) * (readed + 1));
	while(i < readed)
	{
		newnode->content[i] = content[i];
		i++;
	}
	free(content);
	newnode->content[i] = 0;
	newnode->next = NULL;
	last = ft_lstlast(*buffer);
	if (!last)
		*buffer = newnode;
	else
		last->next = newnode;

}
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;
	if (!lst)
		return ;
	tmp = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	
}

char *extract_line(t_list *buffer)
{
	char *line;
	size_t i = 0;
	size_t j = 0;
	if(!buffer)
		return 0;
	allocline(buffer,&line);
	if (line  == 0)
		return 0 ;
	while(buffer)
	{
		j = 0;
		while(buffer->content[j] != '\n' && buffer->content[j])
				{
					line[i] = buffer->content[j];
					i++;
					j++;
				} 
		if (buffer->content[j] == '\n')
		{
			line[i] = '\n';
			i++;
		}
		buffer = buffer->next;
	}
	line[i] = 0;
	return(line);
}

void allocline(t_list *buffer,char **line)
{
	size_t count = 0;
	char c;
	if(!buffer)
		return ;
	while(buffer)
	{
		while((c = buffer->content[count]) != '\n' && buffer->content[count])
				count++;
		buffer = buffer->next;
	}
	if (count == 0 && c != '\n')
	{
		*line = 0;
		return ;
	}
	count++;
	*line = malloc(sizeof(char) * count +1);
}

void make_remain(t_list **buffer)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lstlast(*buffer);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	ft_lstclear(buffer);
	*buffer = clean_node;
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
int ft_check(t_list *buffer)
{
	t_list *last;
	size_t i = 0;

	if(!buffer)
		return 0;
	last = ft_lstlast(buffer);
	while (last->content[i])
	{	
		if(last->content[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}
size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
int main()
{
	 int fd = open("test",O_RDONLY);
	
	printf("%s",get_next_line(fd));
		printf("%s",get_next_line(fd));

	printf("%s",get_next_line(fd));

	printf("%s",get_next_line(fd));

	printf("%s",get_next_line(fd));

	printf("%s",get_next_line(fd));

	printf("%s",get_next_line(fd));

	printf("%s",get_next_line(fd));

	printf("%s",get_next_line(fd));

	printf("%s",get_next_line(fd));

	printf("%s",get_next_line(fd));


	printf("%s",get_next_line(fd));

	printf("%s",get_next_line(fd));



}
