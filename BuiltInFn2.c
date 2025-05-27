#include "exec.h"

typedef struct t_info
{
    int arg_num;
    int status;
    t_word_list *temp;
    const char *path;
} t_info;

int len_args(t_word_list *temp)
{
    int counter;

    counter = 0;
    while (temp)
    {
        counter++;
        temp = temp->next;
    }
    return counter;
}

char *chdir_home(char *path)
{
    int status;
    char *p;

    status = 0;
    path = getenv("HOME");
    if (!path)
    {
        ft_putstr_fd("cd: HOME not set\n", STDERR_FILENO);
        return (NULL);
    }
    status = chdir(path);
    if (status == -1)
    {
        perror("cd");
        return (NULL);
    }
    return (path);
}

char *_old_pwd(t_env *env)
{
    t_env   *temp;

    temp = env;
    while (temp)
    {
        if (ft_strcmp(temp->var, "OLDPWD") == 0)
            return (temp->value);
        temp = temp->next;
    }
    return (NULL);
}

char *privous_path(char *old_path, t_env *env)
{
    if (ft_strcmp(old_path, "-") == 0)
    {
        old_path = _old_pwd(env);
        if (!old_path)
            return (NULL);
    }
    return old_path;
}

void update_env(t_info info, t_env *env)
{
    t_env *temp;
    char *old_pwd;

    temp = env;
    while (temp)
    {
        if (ft_strcmp(temp->var, "PWD") == 0)
        {
            old_pwd = temp->value;
            temp->value = info.path;
            if (temp->value == NULL)
            {
                perror("malloc is failed\n");
                return ;
            }
            break;
        }
        temp = temp->next;
    }
    temp = env;
    while (temp && old_pwd)
    {
        if (ft_strcmp(temp->var, "OLDPWD") == 0)
        {
            temp->value = old_pwd;
            if (temp->value == NULL)
            {
                perror("malloc is failed\n");
                return ;
            }
            break;
        }
        temp = temp->next;
    }
}

void my_cd(t_cmd node, t_env *env)
{
    t_info info;

    info.arg_num = len_args(node.args);
    if (info.arg_num == 0)
    {
        info.path = chdir_home(info.path);
        if (info.path == NULL)
            return;
    }
    else if (info.arg_num == 1)
    {
        if (node.args && node.args->word)
            info.path = privous_path(node.args->word->str, env);
        if (!info.path)
        {
            ft_putstr_fd("cd: invalid argument\n", STDERR_FILENO);
            return;
        }
    }
    else if (info.arg_num > 1)
    {
        ft_putstr_fd("cd: too many arguments\n", STDERR_FILENO);
        return;
    }
    info.status = chdir(info.path);
    if (info.status == -1)
    {
        perror("cd");
        return ;
    }
    
    update_env(info, env);
}

#include <stdio.h>

// Helper function to create environment list
t_env *create_env_node(char *var, char *value)
{
    t_env *new = malloc(sizeof(t_env));
    new->var = ft_strdup(var);
    new->value = ft_strdup(value);
    new->next = NULL;
    return new;
}

// Helper to print environment variables
void print_env(t_env *env)
{
    printf("Current Environment:\n");
    while (env)
    {
        if (ft_strcmp(env->var, "PWD") == 0 || ft_strcmp(env->var, "OLDPWD") == 0)
            printf("  %s=%s\n", env->var, env->value);
        env = env->next;
    }
}

// Helper to create command arguments
t_word_list *create_args(char *arg)
{
    t_word_list *new = malloc(sizeof(t_word_list));
    new->word = malloc(sizeof(t_word));
    new->word->str = ft_strdup(arg);
    new->next = NULL;
    return new;
}

int main(void)
{
    // Initialize environment
    t_env *_env = env();
    char cwd[PATH_MAX];
    
    getcwd(cwd, sizeof(cwd));

    printf("=== Starting Test ===\n");
    print_env(_env);

    // Test 1: cd to valid directory
    printf("\n=== Test 1: cd to /tmp ===\n");
    t_cmd test1;
    test1.args = create_args("/tmp");
    my_cd(test1, _env);
    print_env(_env);

    // Test 2: cd -
    printf("\n=== Test 2: cd - ===\n");
    t_cmd test2;
    test2.args = create_args("-");
    my_cd(test2, _env);
    print_env(_env);

    // Test 3: cd with no arguments (HOME)
    printf("\n=== Test 3: cd (no args) ===\n");
    t_cmd test3;
    test3.args = NULL;
    my_cd(test3, _env);
    print_env(_env);

    // Test 4: cd with multiple arguments
    printf("\n=== Test 4: cd with 2 args ===\n");
    t_cmd test4;
    test4.args = create_args("arg1");
    test4.args->next = create_args("arg2");
    my_cd(test4, _env);
    print_env(_env);

    // Test 5: cd to invalid directory
    printf("\n=== Test 5: cd to invalid path ===\n");
    t_cmd test5;
    test5.args = create_args("/invalid/path");
    my_cd(test5, _env);
    print_env(_env);

    // Cleanup
    // (Implement proper linked list freeing based on your actual structures)
    
    return 0;
}
