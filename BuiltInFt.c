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

typedef struct t_help
{
    char *variable;
    char *pos_equal;
    char *value;
    char *vriable;
    char *arg;
    char *var_val;
    char **new_env;
    t_word_list *temp;
    int len_env;
    int i;

} t_help;

// int leng_env(char **env)
// {
//     int i;

//     i = 0;
//     while (env[i])
//         i++;
//     return (i);
// }

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

void execute_export(t_cmd node, t_env *info)
{
    t_help help;

    help.temp = node.args;
    if (help.temp == NULL)
    {
        // function of env.
        return;
    }
    while (help.temp)
    {
        help.pos_equal = ft_strchr(help.temp->word->str, '=');
        if (help.pos_equal)
        {
            *(help.pos_equal) = '\0';
            help.value = help.pos_equal + 1;
            add_var_to_env(help.temp->word->str, help.value, info);
        }
        else if (!getenv(help.temp->word->str))
            add_var_to_env(help.temp->word->str, "", info);
        help.temp = help.temp->next;
    }
}


void my_cd(t_cmd node)
{
	int		arg_num;
	t_word_list *temp;

	arg_num = 0;
	temp  = node.args;
	while (temp)
	{
		arg_num++;
		temp = temp->next;
	}
	if (arg_num == 2)
		printf("cd: string not in pwd: %s\n", node.args->word->str);
	else if (arg_num > 2)
		perror("cd: too many arguments\n");
    else if (chdir(node.args->word->str))
        perror("cd");
}


void print_env(t_env *env)
{
    while (env)
    {
        printf("%s=%s", env->var, env->value);
        env = env->next;
    }
}

void   free_linked(t_env *head)
{
    t_env   *temp;

    while (head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void    my_exit(t_env *env, t_cmd *head)
{
    free_linked(env);
    free_linked(head);
    exit(0);
}
  

int main() {
    // Allocate memory for words
    t_word *var1 = malloc(sizeof(t_word));
    t_word *var2 = malloc(sizeof(t_word));
    if (!var1 || !var2) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    // Allocate and copy strings
    var1->str = strdup("yah");
    var2->str = strdup("yah=");
    if (!var1->str || !var2->str) {
        perror("strdup failed");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for nodes
    t_word_list *node1 = malloc(sizeof(t_word_list));
    t_word_list *node2 = malloc(sizeof(t_word_list));
    if (!node1 || !node2) {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }

    // Build the linked list
    node1->word = var1;
    node1->next = NULL;
    node2->word = var2;
    node2->next = node1;

    // Create command structure
    t_cmd cmd;
    cmd.args = node2;

    // Test your export function

    t_env *env_info = env(); // Make sure to initialize this properly
    execute_export(cmd, env_info);
    for (int i = 0; env_info; i++)
    {
        printf("var = %s\nvalue = %s\n", env_info->var, env_info->value);
        env_info = env_info->next;
    }
    // Free allocated memory
    free(var1->str);
    free(var2->str);
    free(var1);
    free(var2);
    free(node1);
    free(node2);

    return 0;
}
