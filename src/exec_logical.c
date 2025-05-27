#include "exec.h"
#include <stdlib.h>

int	exec_and(t_executor *executor, t_ast_node *node, t_ctx *ctx)
{
	int	status;
	
	status = exec_node(executor, node->u_content.s_binary.left, ctx);
	// if (executor->child_cout > 0)
		//wait for cheldreen
	if (WEXITSTATUS(status) == EXIT_SUCCESS)
	{
		status = exec_node(executor, node->u_content.s_binary.right, ctx);
		// if (executor->child_cout > 0)
			//wait for cheldreen
	}
	return (status);
}

int	exec_or(t_executor *executor, t_ast_node *node, t_ctx *ctx)
{
	int	status;
	
	status = exec_node(executor, node->u_content.s_binary.left, ctx);
	// if (executor->child_cout > 0)
		//wait for cheldreen
	if (WEXITSTATUS(status) != EXIT_SUCCESS)
	{
		status = exec_node(executor, node->u_content.s_binary.right, ctx);
		// if (executor->child_cout > 0)
			//wait for cheldreen
	}
	return (status);
}

int	exec_logical(t_executor *executor, t_ast_node *node, t_ctx *ctx)
{
	int	status;
	
	if (node->type == NODE_AND)
		status = exec_and(executor, node, ctx);
	else if (node->type == NODE_OR)
		status = exec_or(executor, node, ctx);
	return (status);
}
