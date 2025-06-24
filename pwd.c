#include "builtin.h"

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

int full_arg(t_word_list *temp, char ***arg)
{
    int count = len_args(temp);
    *arg = malloc(sizeof(char *) * (count + 2));
    
    if (!*arg)
    {
        perror("malloc");
        return 0;
    }
    
    (*arg)[0] = "pwd";
    int i = 1;
    
    while (temp && i <= count)
    {
        if (temp->word && temp->word->str)
            (*arg)[i] = temp->word->str;
        else
            (*arg)[i] = "";
        temp = temp->next;
        i++;
    }
    (*arg)[i] = NULL;
    return 1;
}

void my_pwd(t_executor *executor, char **args)
{
    t_word_list *temp = node.args;
    char **arg = NULL;

    if (!full_arg(temp, &arg))
        return;

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
        free(arg);
        return;
    }
    
    if (pid == 0)
    {
        execvp("pwd", arg);
        perror("execvp");
    }
    wait(NULL);
    free(arg);
}

#include <stdio.h>
#include <stdlib.h>

// Helper to create argument list
t_word_list *create_args(int count, char **strs)
{
    t_word_list *head = NULL;
    t_word_list **current = &head;
    
    for (int i = 0; i < count; i++)
    {
        *current = malloc(sizeof(t_word_list));
        (*current)->word = malloc(sizeof(t_word));
        (*current)->word->str = strs[i];
        (*current)->next = NULL;
        current = &(*current)->next;
    }
    return head;
}

int main(void)
{
    printf("=== TEST 1: pwd without arguments ===\n");
    t_cmd test1;
    test1.args = create_args(0, NULL);
    my_pwd(test1);

    printf("\n=== TEST 2: pwd with -P flag ===\n");
    char *args2[] = {"-P"};
    test1.args = create_args(1, args2);
    my_pwd(test1);

    printf("\n=== TEST 3: pwd with multiple arguments ===\n");
    char *args3[] = {"dfsfsd", "-ljsdf"};
    test1.args = create_args(2, args3);
    my_pwd(test1);

    printf("\n=== TEST 4: pwd with NULL args ===\n");
    test1.args = NULL;
    my_pwd(test1);

    // Cleanup
    // Add your linked list freeing logic here
    
    return 0;
}

