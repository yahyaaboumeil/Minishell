#include "exec.h"
// #include "libft/ft_strlen.c"
// #include "libft/ft_strchr.c"
// #include "libft/ft_strncmp.c"
// #include "add_back.c"
// #include "creat_node.c"
// #include "full_env.c"
// #include "stdio.h"
// #include "wait.h"
// #include "string.h"
// #include "libft/ft_strcmp.c"


typedef struct t_info1
{
    char    **new_env;
    int     len_env;
    int     i;
    int     len_var;
    int     j;
    int     we_alloc;
    char *variable;
    t_word_list *temp;

}              t_info1;


void    remove_variable(t_env **env1, char *var)
{
    t_env   *temp;
	t_env	*env;
    int     i = 0;

	env = *env1;
	if (!ft_strcmp(env->var, var))
	{
		env1 = env->next;
		return (free(env));
	}
    while (env)
    {
        if (!ft_strcmp(env->next->var, var))
        {
            temp = env->next;
            env->next = temp->next;
            free(temp);
            return ;
        }
        env = env->next;
    }
}

int check_is_exest_var(char *var, t_env *env)
{
    int i;

    i = 0;
    while (env)
    {
        if (ft_strcmp(env->var, var))
            return (1);
        env = env->next;
    }
    return (0);
}

void    my_unset(char **args, t_env *env)
{
    int i;
    t_info1  info1; 

    i = 0;
    if (!args || !agrs[0])
    {
        printf("unset: not enough arguments\n");
        return ;
    }
    while(args[i])
    {
        if (ft_strchr(agrs[i], '='))
            printf("unset: %s: invalid parameter name\n", args[i]);
        else
            if (check_is_exest_var(args[i], env))
                remove_variable(&env, agrs[i]);
        i++;
    } 
}

// int main() {
//     // Allocate memory for words
//     t_word *var1 = malloc(sizeof(t_word));
//     t_word *var2 = malloc(sizeof(t_word));
//     if (!var1 || !var2) {
//         perror("malloc failed");
//         exit(EXIT_FAILURE);
//     }

//     // Allocate and copy strings
//     var1->str = strdup("yahya=");
//     var2->str = strdup("yah=");
//     if (!var1->str || !var2->str) {
//         perror("strdup failed");
//         exit(EXIT_FAILURE);
//     }

//     // Allocate memory for nodes
//     t_word_list *node1 = malloc(sizeof(t_word_list));
//     t_word_list *node2 = malloc(sizeof(t_word_list));
//     if (!node1 || !node2) {
//         perror("malloc failed");
//         exit(EXIT_FAILURE);
//     }

//     // Build the linked list
//     node1->word = var1;
//     node1->next = NULL;
//     node2->word = var2;
//     node2->next = node1;

//     // Create command structure
//     t_cmd cmd;
//     cmd.args = node2;

//     // Test your export function

//     t_env *env_info = env(); // Make sure to initialize this properly
//     my_unset(cmd, env_info);
//     for (int i = 0; env_info; i++)
//     {
//         printf("var = %s\nvalue = %s\n", env_info->var, env_info->value);
//         env_info = env_info->next;
//     }
//     // Free allocated memory
//     free(var1->str);
//     // free(var2->str);
//     free(var1);
//     // free(var2);
//     free(node1);
//     // free(node2);

//     return 0;
// }
