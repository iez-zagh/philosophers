 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i++])
	;
	return (i);
}

char *substr2(char *str, int begin, int l)
{
	int i = 0;
	if (!l)	
		return (NULL);
	char *res = malloc (l + 1);
	while (l)
	{
		// puts("on")
		res[i++] = str[begin++];
		l--;
	}
	res[begin] ='\0';
	return (res);
}
char *substr3(char *str, int begin)
{
	int i = 0;
	if (!str)	
		return (NULL);
	// printf("buff ==[[%s]]\n", str);
	char *res = malloc (ft_strlen(str) - begin + 1);
	while (str[begin])
	{
		res[i++] = str[begin++];
	}
	res[i] ='\0';
	return (res);
}

char	*ft_one_line(char *str, int start, int end)
{
	if (!str)
		return (NULL);
	// if (!end)
	// 	return (str)
	// printf("%d]]\n", end);
	return (substr2(str, start, end))	;
}

int	ft_strchr(char *str, int a)
{
	if (!str)
		return -1;
	for (int i = 0; i < ft_strlen(str);i++)
	{
		if (str[i] == a){
			return (i);
		}
	}
	return (-1);
}


char	*join(char *s1, char *s2)
{
	char	*res;
	int i=0;
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	res = malloc (ft_strlen(s1) +ft_strlen(s2) +2);\\

	
	while(s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	int j  = 0;
	while(s2[j])
	{
		res[i++] = s2[j++];
	}
	res[i] = '\0';
	return (res);

}
char    *get(int fd)
{
    static	char	*buffer = NULL;
    char		*str;
	// char		*tmp = NULL;

    while (1)
    {
		int j = ft_strchr((char *)buffer, '\n');
		if (j !=  -1)
		{
			char *line = ft_one_line(buffer, 0, j + 1);
			char *tmp = buffer;
			buffer  = substr3(buffer, j+1);
			free(tmp);
			return (line);
		}
		str  = malloc (BUF);
		if (!str)
			return (NULL);
		int  y = read (fd, str, BUF);
		if (!y)
		{
			// puts("hello");
			if (!buffer)
				return (free(str),free(buffer),  NULL);
			if (ft_strlen(buffer) == 1)
				return (free(buffer),buffer=NULL, NULL);
			char *line = ft_one_line(buffer , 0, ft_strlen(buffer));
			free(buffer);free(str);
			buffer = NULL;
			return (line);
		}
		str[y++] = '\0';
		char *tmp =buffer;
		buffer = join(buffer, str);
		free(tmp);
		if (tmp)
			free(str);
    }    
}

void	f()
{
	system("leaks a.out");
}
int main()
{
	atexit(f);
    int fd = open("file.txt", O_RDONLY);   
    char *res = get(fd);
	// while (res)
	// {
    	printf("res == [[%s", res);
		free (res);
		res = get(fd);
    	printf("res == [[%s", res);
		free(res);
		res = get(fd);
    	printf("res == [[%s", res);
		free(res);
		res = get(fd);
    	printf("res == [[%s", res);
		free(res);
		res = get(fd);
    	printf("res == [[%s", res);
		free(res);
    // 	res = get(fd);
	// }
}
