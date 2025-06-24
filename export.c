#include "builtin.h"

typedef struct t_help
{
    char *variable;
    char *pos_equal;
    char *value;
    char *vriable;
    char *arg;
    char *var_val;
    char **new_env;
    int len_env;
    int i;

} t_help;

void add_var_to_env(char *var, char *value, t_env *info)
{
    t_help help;
    t_env *temp;

    if (value[0] == 0)
        return;
    while (info->next->next)
    {
        info = info->next;
    }
    temp = info->next;
    info->next = creatnode(var, value);
    info->next->next = temp;
}

void execute_export(char **args, t_env *info)
{
    t_help help;
    int     i;

    i = 0;
    if (args == NULL)
    {
        // function of env.
        return;
    }
    while (help.temp)
    {
        help.pos_equal = ft_strchr(args[i], '=');
        if (help.pos_equal)
        {
            *(help.pos_equal) = '\0';
            help.value = help.pos_equal + 1;
            add_var_to_env(args[i], help.value, info);
        }
        else if (!getenv(args[i]))
            add_var_to_env(args[i], "", info);
        i++;
    }
}
