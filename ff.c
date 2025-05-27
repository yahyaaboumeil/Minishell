#include<stdio.h> 
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <limits.h> 
#include <stdlib.h>
#include<unistd.h> 
#include <stdio.h>
#include <stdlib.h>  // Required for getenv()
// #include "libft/ft_strcmp.c"
// #include "libft/ft_strlen.c"


#include "exec.h"


extern  char **environ;

typedef struct t_info
{
    char    **new_env;
    int     len_env;
    int     i;
    int     len_var;
    int     j;
    int     we_alloc;
    char *variable;
    t_word_list *temp;

}              t_info;

int leng_env(char **env)
{
    int i;

    i = 0;
    while (env[i])
        i++;
    return (i);
}

void    remove_variable(char *var)
{
    t_info  info;
    static char **previous;
    
    info.len_env = leng_env(environ);
    info.new_env = malloc(sizeof(char *) * (info.len_env));
    if (!info.new_env)
    {
        perror("malloc is failed\n");
        exit(1);
    }
    info.i = 0;
    info.j = 0;
    info.len_var = ft_strlen(var);
    while (info.i < info.len_env)
    {
        if (ft_strcmp(environ[info.i], var))
            info.new_env[info.j++] = environ[info.i];
        info.i++;
    }
    info.new_env[info.j] = NULL;
    environ = info.new_env;
    if (previous)
        free(previous);
    previous = environ;
}

int check_is_exest_var(char *var)
{
    int i;
    int len;
    char *temp;

    i = 0;
    len = ft_strlen(var);
    while (environ[i])
    {
        temp = environ[i++];
        if (!ft_strcmp(temp, var))
            return (1);
    }
    return (0);
}

void    my_unset(t_cmd node)
{
    t_info  info; 

    if (!node.args)
    {
        printf("unset: not enough arguments\n");
        return ;
    }
   info.temp = node.args;
    while(info.temp)
    {
        if (check_is_exest_var(info.temp->word->str))
            remove_variable(info.temp->word->str);
        info.temp = info.temp->next;
    } 
}

int main() {
    
t_word var1 = {.str = "aboumei=ab"};
t_word var2 = {.str = "HOME"};
t_word_list node1 = {.word = &var1, .next = NULL};
t_word_list node2 = {.word = &var2, .next = &node1};
t_cmd cmd = {.args = &node2};


    my_unset(cmd);
    

    for (int i = 0; i < 48; i++)
        printf("%s\n",environ[i]);
    // if (fork())
    // {
    //    char *ptr[] = {"pwd", "-P",NULL};
    //    execv("/bin/pwd", ptr);
    // }

    return 0;
}
