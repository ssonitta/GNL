#include "get_next_line.h"
#include <stdio.h>
int   main(int argc, char **av)
{
  char  *line;
  int   fd1;
    
    
    fd1 = open(av[1], O_RDONLY);
    


    printf("%d\n", get_next_line(fd1, &line));
        free(line);

    return (0);
}
