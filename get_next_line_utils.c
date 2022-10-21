#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return 0;
	while (str[count])
		count++;
	return (count);
}
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (0);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	i = 0;
	str = malloc(len + 1 * sizeof(char));
	if (!str)
		return (0);
	while (i < len && start + i <= ft_strlen(s))
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t len = ft_strlen(s1) + ft_strlen(s2);
	char	*res;

	/*if (!s1 || !s2)
		return (0);*/
	i = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * len);
	if (!res)
		return (0);
	while (i < ft_strlen(s1))
	{
		res[i] = s1[i];
		i++;
	}
	while (i + j < len)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[len] = 0;
	return (res);
}
