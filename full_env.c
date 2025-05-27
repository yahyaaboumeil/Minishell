#include "exec.h"

extern  char **environ;

int leng_env(char **env)
{
    int i;

    i = 0;
    while (env[i])
        i++;
    return (i);
}

void    full_env(t_env **_env)
{
    char    *pos_equal;
    int    i;

    i = 0;
    while (environ[i])
    {
        pos_equal = ft_strchr(environ[i], '=');
        *pos_equal = 0;
        add_back(_env, creatnode(environ[i], pos_equal+1));
        i++;
    }
}

t_env    *env()
{
    t_env   *_env;
    int     len_env;

    _env=NULL;
    if (!env)
    {
        perror("malloc is failed\n");
        exit(1);
    }
    full_env(&_env);
    
    return _env;
}
