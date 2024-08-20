 
#include "get.h"


int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i++])
	;
	return (i);
}

char	*ft_one_line(char *str, int start, int end)
{
	int i = 0;
	
}

int	ft_strchr(char *str, int a)
{
	for (int i = 0; i < ft_strlen(str);i++)
	{
		if (str[i] == a)
			return (str[i]);
	}
	return (-1);
}


char    *get(int fd)
{
    static		*buffer;
    char		*str;
	char		*tmp = NULL;

    while (1)
    {
		if (ft_strchr(buffer, '\n') !=  -1)
		{
			return ();
		}
		str  = malloc (BUF);
		if (!str)
			return (NULL);
		read(fd, str, BUF);
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
