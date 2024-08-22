 
#include "get.h"


int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i++])
	;
	return (i);
}

char *substr2(char *str, int begin, int l)
{
	int i =0;
	char *res = malloc (l + 1);
	while (l--)
	{
		res[i++] = str[begin++];
	}
	res[begin] ='\0';
	return (res);
}

char	*ft_one_line(char *str, int start, int end)
{
	if (!str)
		return (NULL);
	return (substr2(str, start, end))	;
}

int	ft_strchr(char *str, int a)
{
	if (!str)
		return -1;
	for (int i = 0; i < ft_strlen(str);i++)
	{
		if (str[i] == a)
			return (str[i]);
	}
	return (-1);
}


char    *get(int fd)
{
    static		*buffer = NULL;
    char		*str;
	char		*tmp = NULL;

    while (1)
    {
		int j = ft_strchr(buffer, '\n');
		if (j !=  -1)
		{
			return (ft_one_line(buffer, 0, j));
			//sub the buffer to eleminate the returned line
		}
		str  = malloc (BUF);
		if (!str)
			return (NULL);
		if (!read(fd, str, BUF))
		{
			return (NULL);
		}
			puts("hello");
		return (str);
		
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
    printf("%s]]\n", res);
	// res = NULL;
    free (res);
}
