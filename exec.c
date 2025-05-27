#include "exec.h"
#include "libft/libft.h"
#include <fcntl.h>


#define OpenFailed-1
#define CMD 1

typedef struct cmd
{
    char *cmd_ptr;
    char  *path;
    char **arg;

} cmd_info;

typedef struct t_info
{
    t_env   *env;
}               t_info;

typedef struct t_ctx
{
    int fd[2];
    int fd_close;
}           t_ctx;

int    check_is_built_in(t_cmd node)
{
    int len_cmd;
    t_env  *_env;

    _env = env();
    len_cmd = ft_strlen(node.name->str);
    if (!ft_strncmp(node.name->str, CD, len_cmd))
        my_cd(node, _env); 
    else if (!ft_strncmp(node.name->str, PWD, len_cmd)) 
        my_pwd(node);        
    else if (!ft_strncmp(node.name->str, ECHO, len_cmd))
        my_echo(node); 
    else if (!ft_strncmp(node.name->str, EXPORT, len_cmd)) 
            execute_export(node, _env);
    else if (!ft_strncmp(node.name->str, UNSET, len_cmd)) 
            my_unset(node, _env);
    else if (!ft_strncmp(node.name->str, ENV, len_cmd)) 
            print_env(_env);
    else if (!ft_strncmp(node.name->str, EXIT, len_cmd)) 
            my_exit(_env, &node);
    else
        return (0);
    return (1);
}

int is_there_arg(t_cmd *cmd)
{
   return (cmd->args->word->str != NULL);         
}

int redirect(t_cmd *cmd, t_ctx *ctx) 
{
    int fd;

    if  (cmd->redir->type == REDIR_IN) 
    {
        fd = open(cmd->redir->filename, O_CREAT|O_RDONLY);
        if (fd == -1)
            return (OpenFailed);
       ctx->fd[STDIN_FILENO] = fd; 
    }
    else if (cmd->redir->type == REDIR_OUT)
    {
        fd = open(cmd->redir->filename, O_CREAT|O_WRONLY);
        if (fd == -1)
            return (OpenFailed);
       ctx->fd[STDOUT_FILENO] = fd; 
    }
    else if (cmd->redir->type == APPEND_OUT)
    {
        fd = open(cmd->redir->filename, O_CREAT|O_APPEND);
        if (fd == -1)
            return (OpenFailed);
       ctx->fd[STDOUT_FILENO] = fd; 
    }
    return (1);
}

void    redirection(t_cmd *cmd, t_ctx *ctx)
{
    t_redir_list    *redir;

    redir = cmd->redir;
    while (redir)
    {
        if (redirect(cmd, ctx) == -1)
        {
            printf("open failed\n");
            return ;
        }
        redir = redir->next;
    }
}

void    exec_cmd(t_cmd *cmd, char **env, t_ctx ctx)
{
    cmd_info info;

    if (cmd->redir)
    {
       redirct(cmd, &ctx); 
    }
    if (check_is_built_in(*cmd))
       return ; 
    info.path = get_path_cmd(env, cmd->name->str);
    if (is_there_arg(cmd))
        info.arg =  get_arg(cmd);
    else
        info.arg = (char *[]){cmd->name->str, NULL};
    if (fork() == 0)
    {
        dup2(ctx.fd[STDOUT_FILENO], STDOUT_FILENO); 
        dup2(ctx.fd[STDIN_FILENO], STDIN_FILENO); 
        if (ctx.fd_close >= 0)
            close(ctx.fd_close); 
        execve(info.path, info.arg, env);
        printf("minishell: command not found: %s\n", info.arg[0]);
    }
    free_meme(info.arg);
    free(info.path);
}

//void    exic(t_node *node, char **env)
//c{
//    if (node->type == CMD)
        //exic_cmd;
//    else 
        //exic_pipe

}

int main(int ac, char **av, char **env)
{


    return (0);
}
