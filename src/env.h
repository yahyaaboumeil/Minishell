#ifndef ENV_H
#define ENV_H

extern char	**environ;

typedef struct t_env
{
	char **env;
	int	cout;
	int capasity;
}	t_env;

#endif
