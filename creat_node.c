#include "exec.h"

t_env	*creatnode(char *var, char *value)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->var = var;
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
