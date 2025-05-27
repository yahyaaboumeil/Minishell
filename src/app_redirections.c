#include "env.h"
#include "exec.h"
#include <fcntl.h>
#include <unistd.h>

int	open_file(t_redir_list *redir)
{
	int	fd;
	
	if (redir->type == REDIR_IN)	
		fd = open(redir->filename, O_CREAT | O_WRONLY );
	else if (redir->type == REDIR_OUT)
		fd = open(redir->filename, O_CREAT | O_RDONLY);
	else if (redir->type == REDIR_OUT)
		fd = open(redir->filename, O_CREAT | O_APPEND);
	if (fd < 0)
		return (OPEN_ERROR);
	return (fd); 
}

int	simple_redirct(t_redir_list *redir, t_ctx *ctx)
{
	int fd;
	int	redir_to;

	fd = open_file(redir);
	if (fd == OPEN_ERROR)
		return (OPEN_ERROR); 
	if (redir->type == REDIR_OUT)
		redir_to = STDOUT_FILENO;
	else if (redir->type == REDIR_IN)
		redir_to = STDIN_FILENO;
	if (dup2(redir_to, fd) == -1)
		return (close(fd),DUP2_ERROR);
	close(fd);
	if (redir->type == REDIR_OUT || APPEND_OUT)
		ctx->fd[STDOUT_FILENO] = STDOUT_FILENO;
	if (redir->type == REDIR_IN)
		ctx->fd[STDIN_FILENO] = STDIN_FILENO;
	return (0);
}

int	app_redirction(t_executor *executor, t_redir_list *redir ,t_ctx *ctx)
{
	int	status;
	
	while (redir)
	{
		if (redir->type == REDIR_IN || REDIR_OUT || APPEND_OUT)
		{
			status = simple_redirct(redir, ctx);
			if (status != 0)
				return (status);
			//add herdorc
		}
		redir = redir->next;
	}	
	if (ctx->fd[STDIN_FILENO] != STDIN_FILENO)
		if (dup2(STDIN_FILENO, ctx->fd[STDIN_FILENO]) == -1)
			return (DUP2_ERROR);
	if (ctx->fd[STDOUT_FILENO] != STDOUT_FILENO)
		if (dup2(STDOUT_FILENO, ctx->fd[STDOUT_FILENO]) == -1)
			return (DUP2_ERROR);
	if (ctx->cloes != -1)	
		close(ctx->cloes);
	return (0);
}
