#include "exec.h"

int	exec_list(t_executor *executor, t_ast_node *node, t_ctx *ctx)
{
	int status;
	int	i;
	
	i = 0;
	status = 0;
	while (i < node->u_content.s_list.count)
	{
		status = exec_node(executor, node->u_content.s_list.commands[i], ctx);
		if (executor->child_cout > 0)
			//wait for childreen
		i++;	
	}
	return (status);
}
