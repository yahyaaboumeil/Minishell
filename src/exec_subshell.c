#include "exec.h"
#include <sys/wait.h>

int	exec_subshell(t_executor *executor, t_ast_node *node, t_ctx *ctx)
{
	int	pid;
	int	st_redi;
	int	status;
	t_ctx	sub_ctx;
	t_env	*env;

	pid = fork();
	if (pid != 0)
		return (make_exec_error(executor, "fork() is failed", FORK_ERROR), FORK_ERROR);
	else if (pid == 0)
	{
		st_redi = app_redirction(executor, node->redir, ctx);	
		//env = get_env;	
		// if (st_redi != 0)	
		// 	return ()
		status = exec(node->u_content.subshell, env);
		//free(env)
		exit(status);
	}
	waitpid(pid, &status, 0);	
	return (status);
}
