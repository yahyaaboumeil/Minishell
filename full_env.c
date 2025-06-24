#include "builtin.h"

void    full_env(t_env2 **_env, char **env)
{
    char    *pos_equal;
    int    i;

    i = 0;
    while (env[i])
    {
        pos_equal = ft_strchr(env[i], '=');
        *pos_equal = 0;
        add_back(_env, creatnode(env[i], pos_equal+1));
        i++;
    }
}

t_env2    *env(char **v_env)
{
    t_env2   *_env;
    int     len_env;

    _env=NULL;
    if (!env)
    {
        perror("malloc is failed\n");
        exit(1);
    }
    full_env(&_env, v_env);
    
    return _env;
}
