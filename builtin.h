#ifndef BUILTIN_H
# define BUILTIN_H

# include "../common.h"
# include "../minishell/src/executor/exec.h"

typedef	int (*t_builtin_func)(t_executor *, char **);

typedef struct t_env2
{
	char *var;
	char *value;
	t_env2 *next;
} t_env2;

typedef struct s_builtin
{
	char *cmd;
	t_builtin_func f;
}	t_builtin;


t_env2    *env(char **v_env);

/* echo.c */
int	echo(t_executor *executor, char **args);

/* cd.c */
int	cd(t_executor *executor, char **args);

/* pwd.c */
int	pwd(t_executor *executor, char **args);

/* export.c */
int	export(t_executor *executor, char **args);

/* unset.c */
int	unset(t_executor *executor, char **args);

/* env.c */
int	env_cmd(t_executor *executor, char **args);

/* exit.c */
int	exit_cmd(t_executor *executor, char **args);

/* builtin.c*/
int	is_builtin(char *cmd);
int	builtin(t_executor *executor, char **args);
int	run_builtin(t_executor *executor, t_cmd *cmd, char **args, t_ctx *ctx);

#endif /* BUILTIN_H*/
