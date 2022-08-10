#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "simple_shell.h"

void kash_exec(char **args)
{
    pid_t child_pid = fork();

    if (child_pid == 0)
    {
        execvp(args[0], args);
        perror("./shell");
        exit(1);
    }
    else if (child_pid > 0)
    {
	    int status;
	    do
	{
            waitpid(child_pid, &status, WUNTRACED);
        }
	    while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    else
    {
        perror("./shell");
    }
}
