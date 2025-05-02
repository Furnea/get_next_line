#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    if (fd < 0)
    {
        perror("open");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
