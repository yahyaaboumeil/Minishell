#include "exec.h"
#include "env.h"

void	make_exec_error(t_executor *executor, char *messag, t_error_code code)
{
	if (executor->has_err)
		return ;
	executor->has_err = 1;
	executor->err.code = code;
	executor->err.msg = messag;
}

int print_exec_error(t_executor executor)
{
	write(2, executor.err.msg, ft_strlen(executor.err.msg));
	return (executor.err.code);
}

void	init_executor(t_executor *executor, t_env env)
{
	executor->has_err = 0;
	executor->childs = malloc(sizeof(int) * MAX_CHILDS);
	if (!executor->childs)
		make_exec_error(executor, "malloc failed", MALLOC_ERROR);
	executor->child_capacity = MAX_CHILDS;
	executor->env = env; 
	executor->child_cout = 0;
}

int	exec_node(t_executor *executor, t_ast_node *node, t_ctx *ctx)
{
	int status = 0;
	int pid = 0;

	if (executor->has_err)
		return executor->err.code;
	if (!node)
		return (0);
	 if (node->type == NODE_LIST)
		status = exec_list(executor, node, ctx);
	 if (node->type == NODE_AND || node->type == NODE_OR)
		status = exec_logical(executor, node, ctx);
	 if (node->type == NODE_SUBSHELL)
		//status = ft exec_subshell;
	if (node->type == NODE_PIPE)
		//status = ft exec_PIPE;
	if (node->type == NODE_CMD)
	{
		//pid = ft exec_cmd;
		//whait for child
	}
	return status;	
}

int	exec(t_ast_node *node, t_env *env)
{
	int status;
	int pid;
	t_executor executor;
	t_ctx ctx;

	if (node)
		return (0);
	init_executor(&executor, env);
	if (executor.has_err)
		return (make_exec_error(&executor, "malloc Failed", MALLOC_ERROR),
		print_exec_error(executor));
	ctx = (t_ctx){{0,1}, -1};
	exec_node(&executor, node, &ctx);	
}


