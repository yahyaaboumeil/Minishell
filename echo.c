#include "exec.h"

void my_echo(t_executor *executor, char **args)
{
    int is_nw;
    int i;

    is_nw = 0;
    i = 0;
    if (args == NULL)
    {
        printf("\n");
        return;
    }

    if (!ft_strncmp(args[0], "-n", ft_strlen(args[i++])))
        is_nw = 1;
    while (temp)
    {
        printf(agrs[i++]);
        if (args[i] != NULL)
            printf(" ");
    }
    if (is_nw)
        printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

// Helper function to create arguments list
t_word_list *create_args(int count, char **strs) {
    t_word_list *head = NULL;
    t_word_list **current = &head;
    
    for (int i = 0; i < count; i++) {
        *current = malloc(sizeof(t_word_list));
        (*current)->word = malloc(sizeof(t_word));
        (*current)->word->str = strs[i];
        (*current)->next = NULL;
        current = &(*current)->next;
    }
    return head;
}

int main(void) {
    printf("=== TEST 1: No arguments ===\n");
    t_cmd test1 = {.args = NULL};
    my_echo(test1);  // Should print: \n

    printf("\n=== TEST 2: Single argument ===\n");
    char *args2[] = {"Hello"};
    test1.args = create_args(1, args2);
    my_echo(test1);  // Should print: Hello\n

    printf("\n=== TEST 3: With -n flag ===\n");
    char *args3[] = {"-n", "No newline"};
    test1.args = create_args(2, args3);
    my_echo(test1);  // Should print: No newline (no \n)

    printf("\n=== TEST 4: Multiple arguments ===\n");
    char *args4[] = {"Hello", "World", "!"};
    test1.args = create_args(3, args4);
    my_echo(test1);  // Should print: Hello World !\n

    printf("\n=== TEST 5: -n as only argument ===\n");
    char *args5[] = {"-n"};
    test1.args = create_args(1, args5);
    my_echo(test1);  // Should print nothing with no \n

    printf("\n=== TEST 6: Mixed arguments ===\n");
    char *args6[] = {"-n", "First", "Second"};
    test1.args = create_args(3, args6);
    my_echo(test1);  // Should print: First Second (no \n)

    // Add memory cleanup for your linked lists here
    // (Implement proper freeing based on your actual structures)

    return 0;
}