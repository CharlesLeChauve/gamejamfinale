/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarrar <iarrar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:12:10 by iarrar            #+#    #+#             */
/*   Updated: 2023/08/23 16:31:19 by iarrar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "./ft_printf/ft_printf.h"
#include "solong.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *str)
{
	int		i;
	char	*dup;

	i = ft_strlen(str);
	dup = malloc(sizeof (char) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb * size / size != nmemb)
		return (NULL);
	dest = malloc(nmemb * size);
	if (!dest)
		return (NULL);
	ft_bzero(dest, (nmemb * size));
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		s1[i] = '\0';
		i++;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	index;

	index = 0;
	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > i - 1 || s[0] == '\0')
		return (ft_strdup(""));
	if (len <= i - start)
		dest = ft_calloc(len + 1, sizeof(char));
	if (len > i - start)
		dest = ft_calloc(i - start + 1, sizeof(char));
	if (!dest)
		return (NULL);
	while (index < len && s[index + start])
	{
		dest[index] = s[start + index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}


char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*dest;
	char	a;

	dest = (char *)str;
	i = 0;
	a = (char)c;
	if (c < 0)
		c = -c;
	while (str[i])
	{
		if (str[i] == a)
			return (&dest[i]);
		else
			i++;
	}
	if (a == '\0')
		return (&dest[i]);
	return (NULL);
}



int ft_start(const char *str, const char *set)
{
    size_t  len;
    size_t  i;

    i = 0;
    len = ft_strlen(str);

    while (i < len)
    {
        if (ft_strchr(set, str[i]) == NULL)
            break;
        i++;
    }
    return (i);
}

int ft_finish(const char *str, const char *set)
{
    size_t len;
    size_t  i;

    len = ft_strlen(str);
    i = 0;

    while (i <= len - 1)
    {
        if (ft_strchr(set, str[len - 1 - i]) == NULL)
            break;
        i++;
    }
    return(len - i);
}

char *ft_strtrim(const char *s1, const char *set)
{
    int     beg;
    int     fin;
    char    *str;
    int     i;

    i = 0;
    beg = ft_start(s1, set);
    fin = ft_finish(s1, set);

    if (s1 == NULL)
        return (NULL);
    if (set == NULL)
        return (ft_strdup(s1));
    if (beg >= fin)
        return ("");

    str = malloc(sizeof(char) * (fin - beg + 1));
    while (i < fin - beg)
    {
        str[i] = s1[beg + i];
        i++;
    }
    return (str);
}

char	*ft_strtroum(const char *s, int c)
{
	char	set[2];

	set[0] = c;
	set[1] = '\0';
	return (ft_strtrim(s, set));
}

int	ft_first(char const *str, char c)
{
	int			i;
	int			j;
	char		*s;

	s = ft_strtroum(str, c);
	j = 0;
	i = 0;
	if (s[0] == '\0')
	{
		free(s);
		return (-1);
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
		{
			j++;
			i++;
		}
		else
			i++;
	}
	free(s);
	return (j);
}

char	**ft_free(char **str, int c)
{
	int	i;

	i = c;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_segment(char *str, char c)
{
	int		i;
	int		j;
	int		x;
	char	**dest;

	dest = ft_calloc(sizeof (char *), (ft_first(str, c) + 2));
	x = 0;
	i = 0;
	j = 0;
	while (str[i] && x <= ft_first(str, c))
	{
		while (str[i] != c && str[i])
			i++;
		dest[x] = ft_substr(str, j, i - j);
		if (!dest[x])
			return (ft_free(dest, x));
		while (str[i] == c)
			i++;
		j = i;
		x++;
	}
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char		**dest;
	char		*s1;

	s1 = ft_strtroum(s, c);
	if (!s1)
		return (NULL);
	dest = ft_segment(s1, c);
	free(s1);
	return (dest);
}

int	ft_strlens(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}


//fd = open("map.ber", O_RDONLY);
char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = ft_strlens(s1);
	j = ft_strlens(s2);
	dest = malloc(sizeof(char) * (i + j + 1));
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}



char	*get_str(int fd)
{
	int	a;
	static char *buff;
	char	*str;
	
	if (!buff)
		buff = malloc(sizeof(char) * 1);
	str = malloc(sizeof(char) * 5001);
	while (a != 0 && a != -1)
	{
		a = read(fd, str, 5000);
		buff = ft_strjoin(buff, str);
	}
	free(str);
	return (buff);
}

char	**ft_maping(const char *mapname)
{
	int		fd;
	char 	*str;
	char 	**map;
	
	fd = open(mapname, O_RDONLY);
	str = get_str(fd);
	map = ft_split(str, '\n');
	return (map);
}

int main()
{
	char **map;
	int i = 0;
	map = ft_maping("map.ber");
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
