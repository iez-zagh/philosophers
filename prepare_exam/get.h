#ifndef GET_H
# define GET_H

#define BUF 3

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char    *get(int fd);

#endif