#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

void kash_exec(char **args);
char** kash_split_line(char *line);
char* kash_read_line();
void kash_exec(char **args);

#endif
