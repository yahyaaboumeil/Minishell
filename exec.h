#ifndef EXEC_H
#define EXEC_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>
#include "libft/libft.h"

#define ECHO "echo"
#define CD "cd"
#define PWD "pwd"
#define EXPORT "export"
#define UNSET "unset"
#define ENV "env"
#define EXIT "exit"

typedef struct s_astnode t_ast_node;

typedef struct t_env
{
	char *var;
	char *value;
	struct t_env *next;
} t_env;

typedef enum e_node_type
{
	NODE_CMD = 0,
	NODE_SUBSHELL,
	NODE_PIPE,
	NODE_BACKGROUND,
	NODE_AND,
	NODE_OR,
	NODE_LIST
} t_node_type;

typedef struct s_word
{
	char *str;
	int flag;
} t_word;

typedef struct s_word_list
{
	t_word *word;
	struct s_word_list *next;
} t_word_list;

typedef enum e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	APPEND_OUT,
	HEREDOC,
} t_redir_type;

typedef struct s_redir_list
{
	t_redir_type type;
	char *filename;
	struct s_redir_list *next;
} t_redir_list;

typedef struct s_cmd
{
	t_word *name;
	t_word_list *args;
	t_redir_list *redir;
} t_cmd;

struct s_astnode
{
	t_node_type type;
	union
	{
		t_cmd *cmd;
		struct
		{
			t_ast_node *left;
			t_ast_node *right;
		} s_pipe;
		t_ast_node *subshell;
		struct
		{
			t_ast_node *left;
			t_ast_node *right;
		} s_binary;
		struct
		{
			t_ast_node *cmd;
		} s_background;
		struct
		{
			t_ast_node **commands;
			int count;
			int size;
		} s_list;
	} u_content;
};

typedef struct s_error
{
	int code;
	const char *msg;
	const char *ctx;
} t_error;

void add_back(t_env **lst, t_env *new);
t_env *creatnode(char *var, char *value);
t_env *env();
void my_echo(t_cmd node);
void my_cd(t_cmd node, t_env *env);
void my_pwd(t_cmd node);
void my_unset(t_cmd node, t_env *env);
void execute_export(t_cmd node, t_env *info);
void print_env(t_env *env);
void my_exit(t_env *env, t_cmd *head);
// int len_args(t_word_list *temp);

void	free_meme(char **var);
char **get_arg(t_cmd *cmd);
char **ft_split(char const *s, char c);
char *extruct_cmd(char *cmd);
char *get_path_cmd(char **env, char *cmd);

#endif
