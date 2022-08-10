#include <stdio.h>
#include <stdlib.h>
#include "simple_shell.h"

int main()
{
    while (1)
    {
      	 printf("#cisfun$ ");
        char *line = kash_read_line();
        char **tokens = kash_split_line(line);

        if (tokens[0] != NULL)
	{
            kash_exec(tokens);
        }

        free(tokens);
        free(line);
    }
}
