#include "exec.h"

int count_cmd(char **cmd)
{
    int i;

    i = 0;
    while (cmd[i])
        i++;
    return i;
}

char    **get_arg(t_cmd *cmd)
{
    t_word_list *temp;
    char **arg;
    int    i; 

    i = 1;
    temp = cmd->args;
    arg[0] = cmd->name->str;
    while (temp)
    {
        arg[i++] = temp->word->str;
        temp = temp->next;
    }
    arg[i] = NULL;

    return (arg);
}

int strlen_of_cmd(char *cmd)
{
    int i;

    i = 0;
    while (cmd[i] && cmd[i] != ' ')
        i++;
    return i;
}

char    *extruct_cmd(char *cmd)
{
    char    *cmd2;
    char **cmd_flagss;
    int i;
    
    i = 1;
    cmd_flagss = ft_split(cmd, ' ');
    cmd2 = cmd_flagss[0];
    while (cmd_flagss[i])
        free(cmd_flagss[i++]);
    free(cmd_flagss);
    return (cmd2);
}



int main()
{
    
    printf("%d",count_cmd(ft_split("cat -e out.txt", ' ')));
}
